//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_OPEXPRESSION_H
#define LIBANTLR4_OPEXPRESSION_H


#include "Expression.h"
#include <sstream>

class OpExpression : public Expression {
public:
    explicit OpExpression(Expression *lExpr, Expression *rExpr);

    void affect(IrScope *owner) override;

    void renderX86(ostream &o) const override = 0;

protected:
    Expression *lExpr;
    Expression *rExpr;
};

class AddOperation : public OpExpression {
public:
    explicit AddOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class SubOperation : public OpExpression {
public:
    explicit SubOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class TimesOperation : public OpExpression {
public:
    explicit TimesOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class DivOperation : public OpExpression {
public:
    explicit DivOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class ModuloOperation : public OpExpression {
public:
    explicit ModuloOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class ShiftRightOperation : public OpExpression {
public:
    explicit ShiftRightOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class ShiftLeftOperation : public OpExpression {
public:
    explicit ShiftLeftOperation(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class LessCompare : public OpExpression {
public:
    explicit LessCompare(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class LessEqualCompare : public OpExpression {
public:
    explicit LessEqualCompare(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class GreatCompare : public OpExpression {
public:
    explicit GreatCompare(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class GreatEqualCompare : public OpExpression {
public:
    explicit GreatEqualCompare(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class EqualCompare : public OpExpression {
public:
    explicit EqualCompare(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class NotEqualCompare : public OpExpression {
public:
    explicit NotEqualCompare(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class BitwiseAnd : public OpExpression {
public:
    explicit BitwiseAnd(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class BitwiseXor : public OpExpression {
public:
    explicit BitwiseXor(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class BitwiseOr : public OpExpression {
public:
    explicit BitwiseOr(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class LogicalAnd : public OpExpression {
public:
    explicit LogicalAnd(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    int firstLabel;
    int secondLabel;
};

class LogicalOr : public OpExpression {
public:
    explicit LogicalOr(Expression *lExpr, Expression *rExpr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    int firstLabel;
    int secondLabel;
    int thirdLabel;
};

#endif //LIBANTLR4_OPEXPRESSION_H
