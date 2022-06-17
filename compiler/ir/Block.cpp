//
// Created by pauls on 15/06/2022.
//

#include "Block.h"

void Block::addInstruction(IrInstruction *instruction) {
    if (instruction->alwaysReturn) alwaysReturn = true;
    instructions.push_back(instruction);
}

void Block::renderX86(ostream &o) const {
    for (auto instruction: instructions) {
        instruction->renderX86(o);
    }
}

void Block::attachTo(Block *block) {
    block->alwaysReturn = alwaysReturn;
    for (auto i: instructions) {
        block->addInstruction(i);
    }
}

void Block::affect(IrScope *owner) {
    setOwner(owner);
    for (auto i: instructions) {
        i->affect(this);
    }
}

Block::Block() = default;
