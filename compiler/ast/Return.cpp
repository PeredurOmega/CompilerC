//
// Created by pauls on 28/06/2022.
//

#include "Return.h"
#include "../ir/IrReturn.h"
#include "../ir/IrJump.h"


void Return::linearize(IrFunction *fun) {
    expression->linearize(fun);
    fun->append(new IrReturn(expression->var));
    int conditionalJump = owner->conditionalJump();
    if (conditionalJump != -1) {
        fun->append(new IrJump(conditionalJump));
    }
}

void Return::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    expression->setOwner(owner);
}