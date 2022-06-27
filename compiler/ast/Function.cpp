//
// Created by pauls on 15/06/2022.
//

#include "Function.h"
#include "../ir/IrLabel.h"
#include "../ir/IrConstant.h"
#include "../ir/IrNoOp.h"
#include <utility>
#include <iostream>

using namespace std;

IrFunction *Function::linearize() {
    endLabel = owner->getNewLabel();

    auto *fun = new IrFunction(parameters, name);
    Block::linearize(fun);

    auto end = new BasicBlock(new string(".L" + to_string(endLabel)));
    fun->currentBlock->nextTrue = end;
    fun->append(end);

    if (!alwaysReturn) {
        if (name == MAIN && *returnType == PrimaryType::INT) {
            fun->append(new IrConstant(0, new IrRegister(nullptr, new string("eax"), new IntType())));
        } else {
            fun->append(new IrNoOp());
        }
    }
    if (conditionalReturn) {
        fun->append(new IrLabel(".L" + to_string(endLabel)));
    }

    return fun;
}

void Function::setBlock(Block *block) {
    block->attachTo(this);
}

int Function::conditionalJump() {
    if (conditionalReturn) return endLabel;
    else return -1;
}

Parameter::Parameter(PrimaryType *type, string name) : type(type), name(std::move(name)) {}
