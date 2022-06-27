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

protected:
    Expression *lExpr;
    Expression *rExpr;
};

class AddOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class SubOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class TimesOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class DivOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class ModuloOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class ShiftRightOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class ShiftLeftOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class LessCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class LessEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class GreatCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class GreatEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class EqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class NotEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class BitwiseAnd : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class BitwiseXor : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class BitwiseOr : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;
};

class LogicalAnd : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int firstLabel;
    int secondLabel;
};

class LogicalOr : public OpExpression {
public:
    using OpExpression::OpExpression;

    void linearize(IrFunction *fun) override;

    int firstLabel;
    int secondLabel;
    int thirdLabel;
};

#endif //LIBANTLR4_OPEXPRESSION_H
