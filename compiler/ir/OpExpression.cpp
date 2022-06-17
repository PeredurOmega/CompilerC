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