//
// Created by pauls on 16/06/2022.
//

#include "OpExpression.h"

vector<IrInstruction *> *OpExpression::linearize() {
    auto *lInstr = lExpr->linearize();
    auto *rInstr = rExpr->linearize();
    lInstr->insert(lInstr->end(), rInstr->begin(), rInstr->end());
    var = new IrVariable(assignTo, owner->getOffset(assignTo));
    return lInstr;
}


vector<IrInstruction *> *AddOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new AddIrInstruction(lExpr->var, rExpr->var, var));
    return lInstr;
}

vector<IrInstruction *> *SubOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new SubIrInstruction(lExpr->var, rExpr->var, var));
    return lInstr;
}

vector<IrInstruction *> *TimesOperation::linearize() {
    auto *lInstr = OpExpression::linearize();
    lInstr->push_back(new TimesIrInstruction(lExpr->var, rExpr->var, var));
    return lInstr;
}

void TimesOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

DivOperation::DivOperation(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void DivOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cltd" << endl;
    o << "    idivl    " << rExpr->offset << "(%rbp)" << endl;

    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '/'";
    }
    o << endl;
}

void DivOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

ModuloOperation::ModuloOperation(Expression *lExpr, Expression *rExpr)
        : OpExpression(lExpr, rExpr) {}

void ModuloOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cltd" << endl;
    o << "    idivl    " << rExpr->offset << "(%rbp)" << endl;

    o << "    movl    %edx, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '%'";
    }
    o << endl;
}

void ModuloOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

ShiftRightOperation::ShiftRightOperation(Expression *lExpr, Expression *rExpr)
        : OpExpression(lExpr, rExpr) {}

void ShiftRightOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    " << lExpr->offset << "(%rbp), %edx" << endl;
    o << "    movl    %eax, %ecx" << endl;
    o << "    sarl    %cl, %edx" << endl;
    o << "    movl    %edx, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '>>'";
    }
    o << endl;
}

void ShiftRightOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

ShiftLeftOperation::ShiftLeftOperation(Expression *lExpr, Expression *rExpr)
        : OpExpression(lExpr, rExpr) {}

void ShiftLeftOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    " << lExpr->offset << "(%rbp), %edx" << endl;
    o << "    movl    %eax, %ecx" << endl;
    o << "    sall    %cl, %edx" << endl;
    o << "    movl    %edx, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '<<'";
    }
    o << endl;
}

void ShiftLeftOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

LessCompare::LessCompare(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void LessCompare::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cmpl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    setl    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '<'";
    }
    o << endl;
}

void LessCompare::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

LessEqualCompare::LessEqualCompare(Expression *lExpr, Expression *rExpr)
        : OpExpression(lExpr, rExpr) {}

void LessEqualCompare::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cmpl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    setle   %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '<='";
    }
    o << endl;
}

void LessEqualCompare::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

GreatCompare::GreatCompare(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void GreatCompare::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cmpl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    setg    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '>'";
    }
    o << endl;
}

void GreatCompare::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

GreatEqualCompare::GreatEqualCompare(Expression *lExpr, Expression *rExpr)
        : OpExpression(lExpr, rExpr) {}

void GreatEqualCompare::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cmpl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    setge    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '>='";
    }
    o << endl;
}

void GreatEqualCompare::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

EqualCompare::EqualCompare(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void EqualCompare::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cmpl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    sete    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '=='";
    }
    o << endl;
}

void EqualCompare::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

NotEqualCompare::NotEqualCompare(Expression *lExpr, Expression *rExpr)
        : OpExpression(lExpr, rExpr) {}

void NotEqualCompare::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    cmpl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    setne    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '!='";
    }
    o << endl;
}

void NotEqualCompare::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

BitwiseAnd::BitwiseAnd(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void BitwiseAnd::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    andl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '&'";
    }
    o << endl;
}

void BitwiseAnd::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

BitwiseXor::BitwiseXor(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void BitwiseXor::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    xorl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '^'";
    }
    o << endl;
}

void BitwiseXor::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

BitwiseOr::BitwiseOr(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr,
                                                                          rExpr) {}

void BitwiseOr::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    orl     " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '|'";
    }
    o << endl;
}

void BitwiseOr::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

LogicalAnd::LogicalAnd(Expression *lExpr, Expression *rExpr) : OpExpression(
        lExpr, rExpr) {}

void LogicalAnd::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    cmpl    $0, " << lExpr->offset << "(%rbp)" << endl;
    o << "    je      .L" << firstLabel << endl;
    o << "    cmpl    $0, " << rExpr->offset << "(%rbp)" << endl;
    o << "    je      .L" << firstLabel << endl;
    o << "    movl    $1, %eax" << endl;
    o << "    jmp     .L" << secondLabel << endl;
    o << " .L" << firstLabel << ":" << endl;
    o << "    movl    $0, %eax" << endl;
    o << " .L" << secondLabel << ":" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '&&'";
    }
    o << endl;
}

void LogicalAnd::affect(IrScope *owner) {
    OpExpression::affect(owner);
    firstLabel = owner->getNewLabel();
    secondLabel = owner->getNewLabel();
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

LogicalOr::LogicalOr(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr,
                                                                          rExpr) {}

void LogicalOr::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    cmpl    $0, " << lExpr->offset << "(%rbp)" << endl;
    o << "    jne     .L" << firstLabel << endl;
    o << "    cmpl    $0, " << rExpr->offset << "(%rbp)" << endl;
    o << "    je      .L" << secondLabel << endl;
    o << " .L" << firstLabel << ":" << endl;
    o << "    movl    $1, %eax" << endl;
    o << "    jmp     .L" << thirdLabel << endl;
    o << " .L" << secondLabel << ":" << endl;
    o << "    movl    $0, %eax" << endl;
    o << " .L" << thirdLabel << ":" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '&&'";
    }
    o << endl;
}

void LogicalOr::affect(IrScope *owner) {
    OpExpression::affect(owner);
    firstLabel = owner->getNewLabel();
    secondLabel = owner->getNewLabel();
    thirdLabel = owner->getNewLabel();
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}