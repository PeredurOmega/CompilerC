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

void AddOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new AddIrInstruction(var, lExpr->var, rExpr->var));
}

void SubOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new SubIrInstruction(var, lExpr->var, rExpr->var));
}

void TimesOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new TimesIrInstruction(var, lExpr->var, rExpr->var));
}

void DivOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new DivIrInstruction(var, lExpr->var, rExpr->var));
}

void ModuloOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new ModuloIrInstruction(var, lExpr->var, rExpr->var));
}

void ShiftRightOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new ShiftRightIrInstruction(var, lExpr->var, rExpr->var));
}

void ShiftLeftOperation::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new ShiftLeftIrInstruction(var, lExpr->var, rExpr->var));
}

void LessCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new LessCompareIrInstruction(var, lExpr->var, rExpr->var));
}

void LessEqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new LessEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

void GreatCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new GreatCompareIrInstruction(var, lExpr->var, rExpr->var));
}

void GreatEqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new GreatEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

void EqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new EqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

void NotEqualCompare::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new NotEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
}

void BitwiseAnd::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new BitwiseAndIrInstruction(var, lExpr->var, rExpr->var));
}

void BitwiseXor::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new BitwiseXorIrInstruction(var, lExpr->var, rExpr->var));
}

void BitwiseOr::linearize(IrFunction *fun) {
    OpExpression::linearize(fun);
    fun->append(new BitwiseOrIrInstruction(var, lExpr->var, rExpr->var));
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