//
// Created by pauls on 19/06/2022.
//

#include "While.h"
#include "../ir/IrJump.h"
#include "../ir/IrLabel.h"
#include "../ir/IrCompare.h"
#include <sstream>

void WhileStatement::linearize(IrFunction *fun) {
    compareLabel = owner->getNewLabel();
    contentLabel = owner->getNewLabel();
    fun->append(new IrJump(compareLabel));
    fun->append(new IrLabel(".L" + to_string(contentLabel)));
    auto *parent = fun->currentBlock;
    auto *compareBlock = new BasicBlock(new string(".L" + to_string(compareLabel)));
    auto *contentBlock = new BasicBlock(new string(".L" + to_string(contentLabel)));
    auto *endBlock = new BasicBlock(new string(".LEnd" + to_string(compareLabel)));
    parent->nextTrue = compareBlock;
    contentBlock->nextTrue = compareBlock;
    compareBlock->nextTrue = contentBlock;
    compareBlock->nextFalse = endBlock;

    fun->append(contentBlock);
    content->linearize(fun);
    fun->append(compareBlock);
    fun->append(new IrLabel(".L" + to_string(compareLabel)));
    compare->linearize(fun);
    fun->append(new IrCompare(compare->var));
    fun->append(new IrJumpIfNotEqual(contentLabel));
}

void WhileStatement::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    compare->setOwner(owner);
    content->setOwner(owner);
}
