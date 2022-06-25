//
// Created by pauls on 15/06/2022.
//

#include "Function.h"
#include "Expression.h"
#include "../ir/IrLabel.h"
#include "../ir/IrPrologue.h"
#include "../ir/IrCopy.h"
#include "../ir/IrConstant.h"
#include "../ir/IrNoOp.h"
#include "../ir/IrEpilogue.h"
#include <utility>
#include <iostream>

using namespace std;

vector<IrInstruction *> *Function::linearize() {
    endLabel = owner->getNewLabel();
    auto *instr = new vector<IrInstruction *>();
    int stackShift = (int) ((symbolTable.size() / 4) + 1) * 32;
    instr->push_back(new IrLabel(name));
    instr->push_back(new IrPrologue(stackShift));

    int offset = 16;
    for (unsigned int i = 0; i < parameters.size(); ++i) {
        Parameter *parameter = parameters[i];
        if (i < 6) {
            auto *var = new IrVariable(&parameter->name, insertInitializedVariable(parameter->name));
            instr->push_back(new IrCopy(FunctionCall::registers[i], var));
        } else {
            insertParameter(parameter->name, offset);
            offset += 8;
        }
    }
    auto *body = Block::linearize();
    instr->insert(instr->end(), body->begin(), body->end());

    if (!alwaysReturn) {
        if (name == MAIN && *returnType == PrimaryType::INT) {
            instr->push_back(new IrConstant(0, new IrRegister(nullptr, new string("eax"))));
        } else {
            instr->push_back(new IrNoOp());
        }
    }
    if (conditionalReturn) {
        instr->push_back(new IrLabel(".L" + to_string(endLabel)));
    }

    instr->push_back(new IrEpilogue(stackShift));

    return instr;
}

void Function::setBlock(Block *block) {
    block->attachTo(this);
}

int Function::conditionalJump() {
    if (conditionalReturn) return endLabel;
    else return -1;
}

Parameter::Parameter(PrimaryType *type, string name) : type(type), name(std::move(name)) {}
