//
// Created by pauls on 17/06/2022.
//

#include "IfElse.h"
#include "../ir/IrCompare.h"
#include "../ir/IrJump.h"
#include "../ir/IrLabel.h"
#include <sstream>


void IfStatement::linearize(IrFunction *fun) {
    compare->linearize(fun);
    fun->append(new IrCompare(compare->var));

    firstLabel = owner->getNewLabel();
    if (finalLabel == 0) finalLabel = owner->getNewLabel();

    int nextLabel;
    if (elseStatement != nullptr) nextLabel = elseStatement->label = owner->getNewLabel();
    else nextLabel = finalLabel;
    fun->append(new IrJumpIfEqual(nextLabel));

    auto *ifBlock = new BasicBlock(new string(".L" + to_string(firstLabel)));
    auto *parent = fun->currentBlock;
    parent->nextTrue = ifBlock;
    fun->append(ifBlock);
    content->linearize(fun);

    if (elseStatement != nullptr) {
        elseStatement->finalLabel = finalLabel;
        fun->append(new IrJump(finalLabel));
        auto *elseBlock = new BasicBlock(new string(".Else" + to_string(firstLabel)));
        parent->nextFalse = elseBlock;
        fun->append(elseBlock);
        elseStatement->linearize(fun);
    }

    fun->append(new BasicBlock(new string(".L" + to_string(finalLabel))));

    // Closing the branch
    if (finalLabel == firstLabel + 1) {
        fun->append(new IrLabel(".L" + to_string(finalLabel)));
    }
}

void IfStatement::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    compare->setOwner(owner);
    content->setOwner(owner);
    if (elseStatement != nullptr) elseStatement->setOwner(owner);
}

void ElseStatement::linearize(IrFunction *fun) {
    fun->append(new IrLabel(".L" + to_string(label)));
    if (dynamic_cast<IfStatement *>(content) != nullptr) {
        ((IfStatement *) content)->finalLabel = finalLabel;
    }
    content->linearize(fun);
}

void ElseStatement::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    content->setOwner(owner);
}
