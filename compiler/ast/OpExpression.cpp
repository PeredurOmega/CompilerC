//
// Created by pauls on 16/06/2022.
//

#include "OpExpression.h"
#include "../ir/OpIrInstruction.h"
#include "../ir/IrCompare.h"
#include "../ir/IrJump.h"
#include "../ir/IrConstant.h"
#include "../ir/IrLabel.h"
#include "../ir/IrMovzbl.h"
#include "../ir/IrCopy.h"
#include <iostream>

using namespace std;

void OpExpression::linearize(IrFunction *fun) {
    lExpr->linearize(fun);
    rExpr->linearize(fun);
    if (assignTo != nullptr) {
        var = owner->getIrVariable(assignTo);
    } else {
        var = new IrTempVariable(lExpr->var->type);
    }
}

void OpExpression::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    lExpr->setOwner(owner);
    rExpr->setOwner(owner);
}

Expression *OpExpression::propagateConstant() {
    lExpr = lExpr->propagateConstant();
    rExpr = rExpr->propagateConstant();
    if (dynamic_cast<Constant *>(lExpr) != nullptr && dynamic_cast<Constant *>(rExpr) != nullptr) {
        return new Constant(evaluate((Constant *) lExpr, (Constant *) rExpr));
    }
    return this;
}

void AddOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new AddIrInstruction(var, lExpr->var, rExpr->var));
}

int AddOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value + rConst->value;
}

void SubOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new SubIrInstruction(var, lExpr->var, rExpr->var));
}

int SubOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value - rConst->value;
}

void TimesOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new TimesIrInstruction(var, lExpr->var, rExpr->var));
}

int TimesOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value * rConst->value;
}

void DivOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new DivIrInstruction(var, lExpr->var, rExpr->var));
}

int DivOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value / rConst->value;
}

void ModuloOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new ModuloIrInstruction(var, lExpr->var, rExpr->var));
}

int ModuloOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value % rConst->value;
}

void ShiftRightOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new ShiftRightIrInstruction(var, lExpr->var, rExpr->var));
}

int ShiftRightOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value >> rConst->value;
}

void ShiftLeftOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new ShiftLeftIrInstruction(var, lExpr->var, rExpr->var));
}

int ShiftLeftOperation::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value << rConst->value;
}

void LessCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new LessCompareIrInstruction(var, lExpr->var, rExpr->var));
}

int LessCompare::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value < rConst->value;
}

void LessEqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new LessEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

int LessEqualCompare::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value <= rConst->value;
}

void GreatCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new GreatCompareIrInstruction(var, lExpr->var, rExpr->var));
}

int GreatCompare::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value > rConst->value;
}

void GreatEqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new GreatEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

int GreatEqualCompare::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value >= rConst->value;
}

void EqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new EqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

int EqualCompare::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value == rConst->value;
}

void NotEqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new NotEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

int NotEqualCompare::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value != rConst->value;
}

void BitwiseAnd::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new BitwiseAndIrInstruction(var, lExpr->var, rExpr->var));
}

int BitwiseAnd::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value & rConst->value;
}

void BitwiseXor::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new BitwiseXorIrInstruction(var, lExpr->var, rExpr->var));
}

int BitwiseXor::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value ^ rConst->value;
}

void BitwiseOr::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new BitwiseOrIrInstruction(var, lExpr->var, rExpr->var));
}

int BitwiseOr::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value | rConst->value;
}

void LogicalAnd::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    firstLabel = owner->getNewLabel();
    secondLabel = owner->getNewLabel();
    fun->append(new IrCompare(lExpr->var));
    fun->append(new IrJumpIfEqual(firstLabel));
    fun->append(new IrCompare(rExpr->var));
    fun->append(new IrJumpIfEqual(firstLabel));
    fun->append(new IrConstant(1, new IrRegister(nullptr, new string("eax"), new IntType())));
    fun->append(new IrJump(secondLabel));
    fun->append(new IrLabel(".L" + to_string(firstLabel)));
    fun->append(new IrConstant(0, new IrRegister(nullptr, new string("eax"), new IntType())));
    fun->append(new IrLabel(".L" + to_string(secondLabel)));
    fun->append(new IrMobzbl(new IrRegister(nullptr, new string("al"), new IntType()),
                             new IrRegister(nullptr, new string("eax"), new IntType())));
    fun->append(new IrCopy(new IrRegister(nullptr, new string("eax"), new IntType()), var));
}

int LogicalAnd::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value && rConst->value;
}

void LogicalOr::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    firstLabel = owner->getNewLabel();
    secondLabel = owner->getNewLabel();
    thirdLabel = owner->getNewLabel();
    fun->append(new IrCompare(lExpr->var));
    fun->append(new IrJumpIfNotEqual(firstLabel));
    fun->append(new IrCompare(rExpr->var));
    fun->append(new IrJumpIfEqual(secondLabel));
    fun->append(new IrLabel(".L" + to_string(firstLabel)));
    fun->append(new IrConstant(1, new IrRegister(nullptr, new string("eax"), new IntType())));
    fun->append(new IrJump(thirdLabel));
    fun->append(new IrLabel(".L" + to_string(secondLabel)));
    fun->append(new IrConstant(0, new IrRegister(nullptr, new string("eax"), new IntType())));
    fun->append(new IrLabel(".L" + to_string(thirdLabel)));
    fun->append(new IrMobzbl(new IrRegister(nullptr, new string("al"), new IntType()),
                             new IrRegister(nullptr, new string("eax"), new IntType())));
    fun->append(new IrCopy(new IrRegister(nullptr, new string("eax"), new IntType()), var));
}

int LogicalOr::evaluate(Constant *lConst, Constant *rConst) const {
    return lConst->value || rConst->value;
}