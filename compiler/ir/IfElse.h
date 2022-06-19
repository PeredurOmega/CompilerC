//
// Created by pauls on 17/06/2022.
//

#ifndef LIBANTLR4_IFELSE_H
#define LIBANTLR4_IFELSE_H


#include "Expression.h"
#include "Block.h"

class ElseStatement;

class IfStatement : public Expression {
public:

    int finalLabel = 0;

    explicit IfStatement(Expression *compare, IrInstruction *content,
                         ElseStatement *elseStatement);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    int firstLabel;
    Expression *compare;
    IrInstruction *content;
    ElseStatement *elseStatement = nullptr;
};


class ElseStatement : public Expression {
public:

    int finalLabel;

    explicit ElseStatement(IrInstruction *content);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    int label;
    IrInstruction *content;
};


#endif //LIBANTLR4_IFELSE_H
