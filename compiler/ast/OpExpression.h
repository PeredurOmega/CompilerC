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

    vector<IrInstruction *> *linearize() override = 0;

protected:
    Expression *lExpr;
    Expression *rExpr;
};

class AddOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class SubOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class TimesOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class DivOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class ModuloOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class ShiftRightOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class ShiftLeftOperation : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class LessCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class LessEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class GreatCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class GreatEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class EqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class NotEqualCompare : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class BitwiseAnd : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class BitwiseXor : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class BitwiseOr : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;
};

class LogicalAnd : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;

    int firstLabel;
    int secondLabel;
};

class LogicalOr : public OpExpression {
public:
    using OpExpression::OpExpression;

    vector<IrInstruction *> *linearize() override;

    int firstLabel;
    int secondLabel;
    int thirdLabel;
};

#endif //LIBANTLR4_OPEXPRESSION_H
