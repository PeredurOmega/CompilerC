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

    explicit IfStatement(Expression *compare, Instruction *content,
                         ElseStatement *elseStatement);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    int firstLabel;
    Expression *compare;
    Instruction *content;
    ElseStatement *elseStatement = nullptr;
};


class ElseStatement : public Expression {
public:

    int label;

    int finalLabel;

    explicit ElseStatement(Instruction *content);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    Instruction *content;
};


#endif //LIBANTLR4_IFELSE_H
