//
// Created by pauls on 17/06/2022.
//

#ifndef LIBANTLR4_IFELSE_H
#define LIBANTLR4_IFELSE_H


#include "Expression.h"
#include "Block.h"

class ElseStatement;

class IfStatement : public BlockWrapper {
public:

    int finalLabel = 0;
    Expression *compare;
    ElseStatement *elseStatement = nullptr;

    explicit IfStatement(Expression *compare, IrInstruction *content,
                         ElseStatement *elseStatement);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string *> *use() override;

    set<string *> *def() override;

private:
    int firstLabel;
};


class ElseStatement : public BlockWrapper {
public:

    int label;

    int finalLabel;

    explicit ElseStatement(IrInstruction *content);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string *> *use() override;

    set<string *> *def() override;
};


#endif //LIBANTLR4_IFELSE_H
