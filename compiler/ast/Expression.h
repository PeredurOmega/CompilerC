//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_EXPRESSION_H
#define LIBANTLR4_EXPRESSION_H

#include <string>
#include <vector>
#include "../ir/IrElement.h"
#include "Scope.h"
#include "Instruction.h"
#include "Function.h"

using namespace std;

class Expression : public Instruction {
public:
    explicit Expression() : Instruction() {};

    /**
     * Initialized after linearization.
     */
    IrVariable *var;

    /**
     * Optional in case the expression is followed by an assignment.
     * When not nullptr, we should store the value of the expression in %eax.
     */
    string *assignTo = nullptr;

    virtual Expression *propagateConstant() = 0;
};

class FunctionCall : public Expression {
public:
    static const vector<string *> registers;

    explicit FunctionCall(string name, vector<Expression *> *arguments)
            : name(std::move(name)), arguments(arguments) {};

    void linearize(IrFunction *fun) override;

    void setOwner(Scope *owner) override;

    static IrRegister *getRegisterToUse(int position, PrimaryType *type);

    Expression *propagateConstant() override;

private:
    string name;
    vector<Expression *> *arguments;
};

class Constant : public Expression {
public:
    int value;

    explicit Constant(int value) : Expression(), value(value) {}

    void linearize(IrFunction *fun) override;

    Expression *propagateConstant() override;
};

class Variable : public Expression {
public:
    string name;

    explicit Variable(string name) : Expression(), name(std::move(name)) {};

    void linearize(IrFunction *fun) override;

    Expression *propagateConstant() override;
};

class VarExpr : public Expression {
public:
    explicit VarExpr(vector<string *> *varNames, Expression *expr)
            : Expression(), varNames(*varNames), expression(expr) {};

    void linearize(IrFunction *fun) override;

    void setOwner(Scope *owner) override;

    Expression *propagateConstant() override;

private:
    vector<string *> varNames;
    Expression *expression;
};


#endif //LIBANTLR4_EXPRESSION_H
