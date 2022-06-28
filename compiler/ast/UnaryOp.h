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

    void linearize(IrFunction* fun) override = 0;

    void setOwner(Scope *owner) override;

    Expression *propagateConstant() override;

    virtual int evaluate(Constant *rConst) const = 0;

protected:
    Expression *rExpr;
};

class MinusUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    void linearize(IrFunction* fun) override;

    int evaluate(Constant *rConst) const override;
};

class PlusUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    void linearize(IrFunction* fun) override;

    int evaluate(Constant *rConst) const override;
};

class NotUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    void linearize(IrFunction* fun) override;

    int evaluate(Constant *rConst) const override;
};

class BitwiseNotUnary : public UnaryOp {
public:
    using UnaryOp::UnaryOp;

    void linearize(IrFunction* fun) override;

    int evaluate(Constant *rConst) const override;
};


#endif //LIBANTLR4_UNARYOP_H
