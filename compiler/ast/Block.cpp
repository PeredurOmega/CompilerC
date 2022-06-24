//
// Created by pauls on 15/06/2022.
//

#include "Block.h"

void Block::addInstruction(Instruction *instruction) {
    if (instruction->alwaysReturn) {
        alwaysReturn = true;
    }
    if (instruction->conditionalReturn) conditionalReturn = true;
    instruction->setOwner(owner);
    instructions.push_back(instruction);
}

void Block::renderX86(ostream &o) const {
    for (auto instruction: instructions) {
        instruction->renderX86(o);
    }
}

void Block::attachTo(Block *block) {
    block->alwaysReturn = alwaysReturn;
    block->conditionalReturn = conditionalReturn;
    for (auto i: instructions) {
        block->addInstruction(i);
    }
}

void Block::affect(IrScope *owner) {
    if(alwaysReturn) owner->alwaysReturn= alwaysReturn;
    if(conditionalReturn) owner->conditionalReturn= conditionalReturn;
    for (auto i: instructions) {
        i->affect(this);
    }
}

int Block::conditionalJump() {
    if (alwaysReturn) return -1;
    else return owner->conditionalJump();
}

Block::Block() = default;
