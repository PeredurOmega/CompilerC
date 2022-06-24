//
// Created by bmayouddup on 17/06/22.
//

#ifndef LIBANTLR4_UNARYOP_H
#define LIBANTLR4_UNARYOP_H

#include "Expression.h"
#include <sstream>

class UnaryOp : public Expression {
public:
    explicit UnaryOp(Expression *rExpr);

    void affect(IrScope *owner) override;

    void renderX86(ostream &o) const override = 0;

protected:
    Expression *rExpr;
};

class MinusUnary : public UnaryOp {
public:
    explicit MinusUnary(Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class PlusUnary : public UnaryOp {
public:
    explicit PlusUnary(Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class NotUnary : public UnaryOp {
public:
    explicit NotUnary(Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class BitwiseNotUnary : public UnaryOp {
public:
    explicit BitwiseNotUnary(Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};


#endif //LIBANTLR4_UNARYOP_H
