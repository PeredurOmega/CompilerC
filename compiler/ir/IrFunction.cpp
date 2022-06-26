//
// Created by mathis on 26/06/22.
//

#include "IrFunction.h"
#include "IrCopy.h"
#include "../ast/Expression.h"
#include "IrPrologue.h"
#include "IrLabel.h"

void IrFunction::renderX86(ostream &o) const {
    auto *instr = new vector<IrInstruction *>();

    int stackSize = (int) ((basicBlock->stackSize() / 4) + 1) * 16;
    instr->push_back(new IrLabel(name));
    instr->push_back(new IrPrologue(stackSize));

    int offset = 16;
    for (unsigned int i = 0; i < parameters.size(); ++i) {
        auto *parameter = parameters[i];
        //TODO AFFECT
        if (i < 6) {
            auto *var = new IrVariable(&parameter->name, parameter->type);
            instr->push_back(new IrCopy(FunctionCall::registers[i], var));
        } else {
            auto * arg = new IrArgument(&parameter->name, parameter->type, offset);
            offset += 8;
        }
    }

    basicBlock->renderX86(o);

    /* TODO EPILOGUE
    if (!alwaysReturn) {
        if (name == MAIN && *returnType == PrimaryType::INT) {
            instr->push_back(new IrConstant(0, new IrRegister(nullptr, new string("eax"), new IntType())));
        } else {
            instr->push_back(new IrNoOp());
        }
    }
    if (conditionalReturn) {
        instr->push_back(new IrLabel(".L" + to_string(endLabel)));
    }

    instr->push_back(new IrEpilogue(stackShift));
     */
}
