//
// Created by pauls on 16/06/2022.
//

#include "OpExpression.h"

OpExpression::OpExpression(Expression *lExpr, Expression *rExpr) :
        Expression(false), lExpr(lExpr), rExpr(rExpr) {

}

void OpExpression::affect(IrScope *owner) {
    setOwner(owner);
    lExpr->affect(owner);
    rExpr->affect(owner);
}

void OpExpression::renderX86(ostream &o) const {
    lExpr->renderX86(o);
    rExpr->renderX86(o);
}

AddOperation::AddOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) { }

void AddOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %edx" << endl;
    o << "    movl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    addl    %edx, %eax" << endl;

    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '+'";
    }
    o << endl;
}

void AddOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

SubOperation::SubOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) { }

void SubOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %eax" << endl;
    o << "    subl    " << rExpr->offset << "(%rbp), %eax" << endl;

    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '-'";
    }
    o << endl;
}

void SubOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

TimesOperation::TimesOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) { }

void TimesOperation::renderX86(ostream &o) const {
    OpExpression::renderX86(o);
    o << "    movl    " << lExpr->offset << "(%rbp), %edx" << endl;
    o << "    movl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    imull    %edx, %eax" << endl;

    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '*'";
    }
    o << endl;
}

void TimesOperation::affect(IrScope *owner) {
    OpExpression::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

DivOperation::DivOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) { }

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

ModuloOperation::ModuloOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) { }

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

ShiftRightOperation::ShiftRightOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

ShiftLeftOperation::ShiftLeftOperation(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

LessCompare::LessCompare(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

LessEqualCompare::LessEqualCompare(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

GreatCompare::GreatCompare(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

GreatEqualCompare::GreatEqualCompare(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

EqualCompare::EqualCompare(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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

NotEqualCompare::NotEqualCompare(Expression *lExpr, Expression *rExpr) : OpExpression(lExpr, rExpr) {}

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