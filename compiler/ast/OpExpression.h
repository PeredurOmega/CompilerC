//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_OPEXPRESSION_H
#define LIBANTLR4_OPEXPRESSION_H


#include "Expression.h"
#include <sstream>

class OpExpression : public Expression {
public:
    explicit OpExpression(Expression *lExpr, Expression *rExpr)
            : Expression(), lExpr(lExpr), rExpr(rExpr) {};

    void linearize(IrFunction *fun) override = 0;

    void setOwner(Scope *owner) override;

    Expression *propagateConstant() override;

    virtual int evaluate(Constant *lConst, Constant *rConst) const = 0;

protected:
    Expression *lExpr;
    Expression *rExpr;
};

class AddOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class SubOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class TimesOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class DivOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class ModuloOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class ShiftRightOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class ShiftLeftOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class LessCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class LessEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class GreatCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class GreatEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class EqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class NotEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class BitwiseAnd : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class BitwiseXor : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class BitwiseOr : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;
};

class LogicalAnd : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;

    int firstLabel;
    int secondLabel;
};

class LogicalOr : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int evaluate(Constant *lConst, Constant *rConst) const override;

    int firstLabel;
    int secondLabel;
    int thirdLabel;
};

#endif //LIBANTLR4_OPEXPRESSION_H
