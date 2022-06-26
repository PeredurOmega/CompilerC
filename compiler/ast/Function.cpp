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

    int offset = 16;
    for (unsigned int i = 0; i < parameters.size(); ++i) {
        auto *parameter = parameters[i];
        if (i < 6) {
            auto *var = new IrVariable(&parameter->name, declareVariable(&parameter->name, parameter->type));
            instr->push_back(new IrCopy(FunctionCall::registers[i], var));
        } else {
            declareVariable(&parameter->name, parameter->type);
            offset += 8;
        }
    }
    auto *body = Block::linearize();
    instr->insert(instr->end(), body->begin(), body->end());

    int stackShift = (int) ((varTable.size() / 4) + 1) * 16;
    instr->insert(instr->begin(), new IrPrologue(stackShift));
    instr->insert(instr->begin(), new IrLabel(name));

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
