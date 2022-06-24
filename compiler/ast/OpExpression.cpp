//
// Created by pauls on 16/06/2022.
//

#include "OpExpression.h"
#include "../ir/OpIrInstruction.h"

vector<IrInstruction *> *OpExpression::linearize() {
    auto *lInstr = lExpr->linearize();
    auto *rInstr = rExpr->linearize();
    lInstr->insert(lInstr->end(), rInstr->begin(), rInstr->end());
    var = new IrVariable(assignTo, owner->getOffset(assignTo));
    return lInstr;
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
    lInstr->push_back(new DivIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *LogicalAnd::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new LogicalAndIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

vector<IrInstruction *> *LogicalOr::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new LogicalOrIrInstruction(var, lExpr->var, rExpr->var));
    return lInstr;
}

//void LogicalAnd::renderX86(ostream &o) const {
//    OpExpression::renderX86(o);
//    o << "    cmpl    $0, " << lExpr->offset << "(%rbp)" << endl;
//    o << "    je      .L" << firstLabel << endl;
//    o << "    cmpl    $0, " << rExpr->offset << "(%rbp)" << endl;
//    o << "    je      .L" << firstLabel << endl;
//    o << "    movl    $1, %eax" << endl;
//    o << "    jmp     .L" << secondLabel << endl;
//    o << " .L" << firstLabel << ":" << endl;
//    o << "    movl    $0, %eax" << endl;
//    o << " .L" << secondLabel << ":" << endl;
//    o << "    movzbl  %al, %eax" << endl;
//    o << "    movl    %eax, " << offset << "(%rbp) #";
//    if (assignTo != nullptr) {
//        o << *assignTo;
//    } else {
//        o << "Temp operation result '&&'";
//    }
//    o << endl;
//}

//void LogicalOr::renderX86(ostream &o) const {
//    OpExpression::renderX86(o);
//    o << "    cmpl    $0, " << lExpr->offset << "(%rbp)" << endl;
//    o << "    jne     .L" << firstLabel << endl;
//    o << "    cmpl    $0, " << rExpr->offset << "(%rbp)" << endl;
//    o << "    je      .L" << secondLabel << endl;
//    o << " .L" << firstLabel << ":" << endl;
//    o << "    movl    $1, %eax" << endl;
//    o << "    jmp     .L" << thirdLabel << endl;
//    o << " .L" << secondLabel << ":" << endl;
//    o << "    movl    $0, %eax" << endl;
//    o << " .L" << thirdLabel << ":" << endl;
//    o << "    movzbl  %al, %eax" << endl;
//    o << "    movl    %eax, " << offset << "(%rbp) #";
//    if (assignTo != nullptr) {
//        o << *assignTo;
//    } else {
//        o << "Temp operation result '&&'";
//    }
//    o << endl;
//}
