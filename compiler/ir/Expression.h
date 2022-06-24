//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_EXPRESSION_H
#define LIBANTLR4_EXPRESSION_H

#include <string>
#include <vector>
#include "IrElement.h"
#include "IrScope.h"
#include "IrInstruction.h"
#include "Function.h"

using namespace std;

class Expression : public IrInstruction {
public:
    explicit Expression();

    /**
     * Initialized when added to a Block through affect.
     */
    int offset;

    /**
     * Optional in case the expression is followed by an assignment.
     * When not nullptr, we should store the value of the expression in %eax.
     */
    string *assignTo = nullptr;

    set<string*>* use() override = 0;

    set<string*>* def() override = 0;
};

class FunctionCall : public Expression {
public:
    explicit FunctionCall(vector<string *> *parameters);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    vector<string *> *parameters;
};

class Return : public Expression {
public:
    explicit Return(Expression *expression);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string*>* use() override;

    set<string*>* def() override;

private:
    Expression *expression;
};

class Constant : public Expression {
public:
    int value;

    explicit Constant(int value);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string*>* use() override;

    set<string*>* def() override;
};

class Variable : public Expression {
public:
    string name;

    explicit Variable(string name);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string*>* use() override;

    set<string*>* def() override;
};

class VarExpr : public Expression {
public:
    explicit VarExpr(vector<string *> *varNames, Expression *expr);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string*>* use() override;

    set<string*>* def() override;

    vector<string *> varNames;
    Expression *expression;
    vector<int> offsets;
};

class BlockWrapper : public Expression {
public:
    explicit BlockWrapper(IrInstruction *content);

    IrInstruction *content;
};


#endif //LIBANTLR4_EXPRESSION_H
