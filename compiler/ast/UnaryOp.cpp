//
// Created by bmayouddup on 17/06/22.
//

#include "UnaryOp.h"
#include "../ir/UnaryOpIrInstruction.h"
#include "../ir/IrCopy.h"

void UnaryOp::linearize(IrFunction *fun) {
    rExpr->linearize(fun);
    if (assignTo != nullptr) {
        var = new IrVariable(assignTo, owner->getType(assignTo));
    } else {
        var = new IrTempVariable(rExpr->var->type);
    }
}

void UnaryOp::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    rExpr->setOwner(owner);
}

void MinusUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new MinusUnaryIrInstruction(var, rExpr->var));
}

void PlusUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new IrCopy(rExpr->var, var));
}

void NotUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new NotUnaryIrInstruction(var, rExpr->var));
}

void BitwiseNotUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new BitwiseNotUnaryIrInstruction(var, rExpr->var));
}
