//
// Created by pauls on 19/06/2022.
//

#ifndef LIBANTLR4_WHILE_H
#define LIBANTLR4_WHILE_H


#include "Expression.h"

class WhileStatement : public Expression {
public:

    explicit WhileStatement(Expression *compare, Instruction *content);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

private:
    Expression *compare;
    Instruction *content;
    int compareLabel;
    int contentLabel;
};

#endif //LIBANTLR4_WHILE_H
