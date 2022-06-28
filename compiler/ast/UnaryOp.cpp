//
// Created by bmayouddup on 17/06/22.
//

#include "UnaryOp.h"
#include "../ir/UnaryOpIrInstruction.h"
#include "../ir/IrCopy.h"

void UnaryOp::linearize(IrFunction *fun) {
    rExpr->linearize(fun);
    if (assignTo != nullptr) {
        var = owner->getIrVariable(assignTo);
    } else {
        var = new IrTempVariable(rExpr->var->type);
    }
}

void UnaryOp::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    rExpr->setOwner(owner);
}

Expression *UnaryOp::propagateConstant() {
    rExpr = rExpr->propagateConstant();
    if (dynamic_cast<Constant *>(rExpr) != nullptr) {
        return new Constant(evaluate((Constant *) rExpr));
    }
    return this;
}

void MinusUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new MinusUnaryIrInstruction(var, rExpr->var));
}

int MinusUnary::evaluate(Constant *rConst) const {
    return -rConst->value;
}

void PlusUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new IrCopy(rExpr->var, var));
}

int PlusUnary::evaluate(Constant *rConst) const {
    return rConst->value;
}

void NotUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new NotUnaryIrInstruction(var, rExpr->var));
}

int NotUnary::evaluate(Constant *rConst) const {
    return !rConst->value;
}

void BitwiseNotUnary::linearize(IrFunction *fun) {
    UnaryOp::linearize(fun);
    fun->append(new BitwiseNotUnaryIrInstruction(var, rExpr->var));
}

int BitwiseNotUnary::evaluate(Constant *rConst) const {
    return ~rConst->value;
}
