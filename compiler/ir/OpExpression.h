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

#endif //LIBANTLR4_OPEXPRESSION_H
