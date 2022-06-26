//
// Created by bmayouddup on 17/06/22.
//

#ifndef LIBANTLR4_UNARYOP_H
#define LIBANTLR4_UNARYOP_H

#include "Expression.h"
#include <sstream>

class UnaryOp : public Expression {
public:
    explicit UnaryOp(Expression *rExpr) : Expression(), rExpr(rExpr) { };

    vector<IrInstruction *> *linearize() override = 0;

    void setOwner(Scope *owner) override;

protected:
    Expression *rExpr;
};

class MinusUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    vector<IrInstruction *> *linearize() override;
};

class PlusUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    vector<IrInstruction *> *linearize() override;
};

class NotUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    vector<IrInstruction *> *linearize() override;
};

class BitwiseNotUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    vector<IrInstruction *> *linearize() override;
};


#endif //LIBANTLR4_UNARYOP_H
