//
// Created by pauls on 19/06/2022.
//

#ifndef LIBANTLR4_WHILE_H
#define LIBANTLR4_WHILE_H


#include "Expression.h"

class WhileStatement : public Instruction {
public:

    explicit WhileStatement(Expression *compare, Instruction *content)
            : Instruction(), compare(compare), content(content) {};

    vector<IrInstruction *> *linearize() override;

private:
    Expression *compare;
    Instruction *content;
    int compareLabel;
    int contentLabel;
};

#endif //LIBANTLR4_WHILE_H
