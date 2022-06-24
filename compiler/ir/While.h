//
// Created by pauls on 19/06/2022.
//

#ifndef LIBANTLR4_WHILE_H
#define LIBANTLR4_WHILE_H


#include "Expression.h"

class WhileStatement : public BlockWrapper {
public:

    Expression *compare;

    explicit WhileStatement(Expression *compare, IrInstruction *content);

    void renderX86(ostream &o) const override;

    void affect(IrScope *owner) override;

    set<string*>* use() override;

    set<string*>* def() override;
private:
    int compareLabel;
    int contentLabel;
};

#endif //LIBANTLR4_WHILE_H
