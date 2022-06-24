//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_EXPRESSION_H
#define LIBANTLR4_EXPRESSION_H

#include <string>
#include <vector>
#include "IrElement.h"
#include "IrScope.h"
#include "Instruction.h"
#include "Function.h"

using namespace std;

class Expression : public Instruction {
public:
    explicit Expression();

    /**
     * Initialized after linearization.
     */
    IrVariable *var;

    /**
     * Optional in case the expression is followed by an assignment.
     * When not nullptr, we should store the value of the expression in %eax.
     */
    string *assignTo = nullptr;
};

class FunctionCall : public Expression {
public:
    explicit FunctionCall(string name, vector<Expression *> *arguments);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    string name;
    vector<Expression *> *arguments;
};

class Return : public Expression {
public:
    explicit Return(Expression *expression);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    Expression *expression;
};

class Constant : public Expression {
public:
    int value;

    explicit Constant(int value);

    vector<IrInstruction *> *linearize() override;
};

class Variable : public Expression {
public:
    string name;

    explicit Variable(string name);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;
};

class VarExpr : public Expression {
public:
    explicit VarExpr(vector<string *> *varNames, Expression *expr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    vector<string *> varNames;
    Expression *expression;
    vector<int> offsets;
};


#endif //LIBANTLR4_EXPRESSION_H
