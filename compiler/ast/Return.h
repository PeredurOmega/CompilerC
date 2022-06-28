//
// Created by pauls on 28/06/2022.
//

#ifndef LIBANTLR4_RETURN_H
#define LIBANTLR4_RETURN_H


#include "Expression.h"

class Return : public Instruction {
public:
    explicit Return(Expression *expression) : Instruction(), expression(expression) {
        alwaysReturn = true;
    };

    void linearize(IrFunction *fun) override;

    void setOwner(Scope *owner) override;

private:
    Expression *expression;
};

#endif //LIBANTLR4_RETURN_H
