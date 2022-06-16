//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_EXPRESSION_H
#define LIBANTLR4_EXPRESSION_H

#include <string>
#include "IrElement.h"
#include "IrScope.h"
#include "IrInstruction.h"

using namespace std;

class Expression : public IrInstruction {
public:
    explicit Expression(bool alwaysReturn);

    /**
     * Initialized when added to a Block through affect.
     */
    int offset;
};

class Return : public Expression {
public:
    explicit Return(Expression *expression);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    Expression *expression;
};

class Assignment : public Expression {
public:
    string to;

    explicit Assignment(string to, Expression *expression);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    Expression *expression;
};

class Constant : public Expression {
public:
    int value;

    explicit Constant(int value);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class Variable : public Expression {
public:
    string name;

    explicit Variable(string name);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class OpExpression: Expression {

};

#endif //LIBANTLR4_EXPRESSION_H
