//
// Created by bmayouddup on 17/06/22.
//

#include "UnaryOp.h"
#include "../ir/UnaryOpIrInstruction.h"
#include "../ir/IrCopy.h"

vector<IrInstruction *> *UnaryOp::linearize() {
    auto *rInstr = rExpr->linearize();
    var = new IrVariable(assignTo, owner->getOffset(assignTo));
    return rInstr;
}

void UnaryOp::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    rExpr->setOwner(owner);
}

vector<IrInstruction *> *MinusUnary::linearize() {
    auto *rInstr = UnaryOp::linearize();
    rInstr->push_back(new MinusUnaryIrInstruction(var, rExpr->var));
    return rInstr;
}

vector<IrInstruction *> *PlusUnary::linearize() {
    auto *rInstr = UnaryOp::linearize();
    rInstr->push_back(new IrCopy(rExpr->var, var));
    return rInstr;
}

vector<IrInstruction *> *NotUnary::linearize() {
    auto *rInstr = UnaryOp::linearize();
    rInstr->push_back(new NotUnaryIrInstruction(var, rExpr->var));
    return rInstr;
}

vector<IrInstruction *> *BitwiseNotUnary::linearize() {
    auto *rInstr = UnaryOp::linearize();
    rInstr->push_back(new BitwiseNotUnaryIrInstruction(var, rExpr->var));
    return rInstr;
}
