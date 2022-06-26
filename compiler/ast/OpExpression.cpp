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

vector<IrInstruction *> *OpExpression::linearize() {
    auto *lInstr = lExpr->linearize();
    auto *rInstr = rExpr->linearize();
    lInstr->insert(lInstr->end(), rInstr->begin(), rInstr->end());
    var = new IrVariable(assignTo, owner->getOffset(assignTo));
    return lInstr;
}

void OpExpression::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    lExpr->setOwner(owner);
    rExpr->setOwner(owner);
}

vector<IrInstruction *> *AddOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new AddIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *SubOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new SubIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *TimesOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new TimesIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *DivOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new DivIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *ModuloOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new ModuloIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *ShiftRightOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new ShiftRightIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *ShiftLeftOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new ShiftLeftIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *LessCompare::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new LessCompareIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *LessEqualCompare::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new LessEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *GreatCompare::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new GreatCompareIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *GreatEqualCompare::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new GreatEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *EqualCompare::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new EqualCompareIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *NotEqualCompare::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new NotEqualCompareIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *BitwiseAnd::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new BitwiseAndIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *BitwiseXor::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new BitwiseXorIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *BitwiseOr::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new BitwiseOrIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *LogicalAnd::linearize() {
    auto *lInstr = OpExpression::linearize();
    firstLabel = owner->getNewLabel();
    secondLabel = owner->getNewLabel();
    lInstr->push_back(new IrCompare(lExpr->var));
    lInstr->push_back(new IrJumpIfEqual(firstLabel));
    lInstr->push_back(new IrCompare(rExpr->var));
    lInstr->push_back(new IrJumpIfEqual(firstLabel));
    lInstr->push_back(new IrConstant(1, new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrJump(secondLabel));
    lInstr->push_back(new IrLabel(".L" + to_string(firstLabel)));
    lInstr->push_back(new IrConstant(0, new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrLabel(".L" + to_string(secondLabel)));
    lInstr->push_back(new IrConstant(0, new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrMobzbl(new IrRegister(nullptr, new string("al")),
                                   new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrCopy(new IrRegister(nullptr, new string("eax")), var));
    return lInstr;
}

vector<IrInstruction *> *LogicalOr::linearize() {
    auto *lInstr = OpExpression::linearize();
    firstLabel = owner->getNewLabel();
    secondLabel = owner->getNewLabel();
    thirdLabel = owner->getNewLabel();
    lInstr->push_back(new IrCompare(lExpr->var));
    lInstr->push_back(new IrJumpIfNotEqual(firstLabel));
    lInstr->push_back(new IrCompare(rExpr->var));
    lInstr->push_back(new IrJumpIfEqual(secondLabel));
    lInstr->push_back(new IrLabel(".L" + to_string(firstLabel)));
    lInstr->push_back(new IrConstant(1, new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrJump(thirdLabel));
    lInstr->push_back(new IrLabel(".L" + to_string(secondLabel)));
    lInstr->push_back(new IrConstant(0, new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrLabel(".L" + to_string(thirdLabel)));
    lInstr->push_back(new IrMobzbl(new IrRegister(nullptr, new string("al")),
                                   new IrRegister(nullptr, new string("eax"))));
    lInstr->push_back(new IrCopy(new IrRegister(nullptr, new string("eax")), var));
    return lInstr;
}
