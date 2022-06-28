//
// Created by pauls on 17/06/2022.
//

#ifndef LIBANTLR4_IFELSE_H
#define LIBANTLR4_IFELSE_H


#include "Expression.h"
#include "Block.h"

class ElseStatement;

class IfStatement : public Instruction {
public:

    int finalLabel = 0;

    explicit IfStatement(Expression *compare, Instruction *content, ElseStatement *elseStatement)
            : Instruction(), compare(compare), content(content), elseStatement(elseStatement) {};

    void linearize(IrFunction *fun) override;

    void setOwner(Scope *owner) override;

private:
    int firstLabel;
    Expression *compare;
    Instruction *content;
    ElseStatement *elseStatement = nullptr;
};


class ElseStatement : public Instruction {
public:

    int label;

    int finalLabel;

    explicit ElseStatement(Instruction *content) : Instruction(), content(content) {};

    void linearize(IrFunction* fun) override;

    void setOwner(Scope *owner) override;

private:
    Instruction *content;
};


#endif //LIBANTLR4_IFELSE_H
