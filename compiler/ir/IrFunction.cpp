//
// Created by mathis on 26/06/22.
//

#include "IrFunction.h"
#include "../ast/Expression.h"
#include "IrLabel.h"
#include "IrPrologue.h"
#include "IrCopy.h"
#include "IrEpilogue.h"
#include <sstream>

void IrFunction::assignMemory() {
    int offset = 16;
    for (int i = 0; i < (int) parameters.size(); ++i) {
        auto *parameter = parameters[i];
        if (i < 6) {
            mainScope->insertInitializedVariable(parameter->name, parameter->type);
        } else {
            mainScope->insertParameter(parameter->name, offset);
            offset += 8;
        }
    }

    for (auto *block: *basicBlocks) {
        for (auto *instr: *block->instr) {
            instr->scope->syncOffset();
            instr->assignMemory();
        }
    }
}

void IrFunction::renderX86(ostream &o) const {
    (new IrLabel(name))->renderX86(o);
    int stackShift = abs(stackSize) + (16 - (abs(stackSize) % 16));
    (new IrPrologue(stackShift))->renderX86(o);

    for (int i = 0; i < min((int) parameters.size(), 6); ++i) {
        auto *parameter = parameters[i];
        auto *var = new IrVariable(&parameter->name, parameter->type);
        var->assignMemory(mainScope);
        (new IrCopy(FunctionCall::getRegisterToUse(i, parameter->type), var))->renderX86(o);
    }

    for (auto *block: *basicBlocks) {
        for (auto *instr: *block->instr) {
            instr->renderX86(o);
        }
    }

    (new IrEpilogue(stackShift))->renderX86(o);
}

void IrFunction::append(IrInstruction *instruction) {
    instruction->scope = currentScope;
    currentBlock->instr->push_back(instruction);
}

void IrFunction::append(vector<IrInstruction *> *instruction) {
    for (auto *instr: *instruction) {
        instr->scope = currentScope;
    }
    currentBlock->instr->insert(currentBlock->instr->end(), instruction->begin(), instruction->end());
}

void IrFunction::append(BasicBlock *block) {
    currentBlock = block;
    basicBlocks->push_back(block);
}
