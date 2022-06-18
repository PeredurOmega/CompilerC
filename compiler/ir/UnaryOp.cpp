//
// Created by bmayouddup on 17/06/22.
//

#include "UnaryOp.h"

UnaryOp::UnaryOp(Expression *rExpr) : Expression(), rExpr(rExpr) {
}

void UnaryOp::affect(IrScope *owner) {
    setOwner(owner);
    rExpr->affect(owner);
}

void UnaryOp::renderX86(ostream &o) const {
    rExpr->renderX86(o);
}

MinusUnary::MinusUnary(Expression *rExpr) : UnaryOp(rExpr) {}

void MinusUnary::renderX86(ostream &o) const {
    UnaryOp::renderX86(o);
    o << "    negl    " << rExpr->offset << "(%rbp)" << endl;

    o << "    movl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '-'";
    }
    o << endl;
}

void MinusUnary::affect(IrScope *owner) {
    UnaryOp::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

PlusUnary::PlusUnary(Expression *rExpr) : UnaryOp(rExpr) {}

void PlusUnary::renderX86(ostream &o) const {
    UnaryOp::renderX86(o);
}

void PlusUnary::affect(IrScope *owner) {
    UnaryOp::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

NotUnary::NotUnary(Expression *rExpr) : UnaryOp(rExpr) {}

void NotUnary::renderX86(ostream &o) const {
    UnaryOp::renderX86(o);
    o << "    cmpl    $0, " << rExpr->offset << "(%rbp)" << endl;
    o << "    sete    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;

    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '!'";
    }
    o << endl;
}

void NotUnary::affect(IrScope *owner) {
    UnaryOp::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}

BitwiseNotUnary::BitwiseNotUnary(Expression *rExpr) : UnaryOp(rExpr) {}

void BitwiseNotUnary::renderX86(ostream &o) const {
    UnaryOp::renderX86(o);
    o << "    notl    " << rExpr->offset << "(%rbp)" << endl;
    o << "    movl    " << rExpr->offset << "(%rbp), %eax" << endl;
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '~'";
    }
    o << endl;
}

void BitwiseNotUnary::affect(IrScope *owner) {
    UnaryOp::affect(owner);
    if (assignTo != nullptr) {
        offset = owner->getOffset(*assignTo);
    } else {
        offset = owner->insertTempVariable();
    }
}