//
// Created by pauls on 15/06/2022.
//

#include "Block.h"

void Block::addInstruction(Instruction *instruction) {
    if (instruction->alwaysReturn) {
        alwaysReturn = true;
    }
    if (instruction->conditionalReturn) {
        conditionalReturn = true;
    }
    instruction->setOwner(this);
    instructions.push_back(instruction);
}

void Block::attachTo(Block *block) {
    block->alwaysReturn = alwaysReturn;
    block->conditionalReturn = conditionalReturn;
    for (auto i: instructions) {
        block->addInstruction(i);
    }
}

int Block::conditionalJump() {
    if (alwaysReturn) return -1;
    else return owner->conditionalJump();
}

vector<IrInstruction *> *Block::linearize() {
    auto *instr = new vector<IrInstruction *>();
    for (auto *inst: instructions) {
        auto *l = inst->linearize();
        instr->insert(instr->end(), l->begin(), l->end());
    }
    return instr;
}

void Block::setOwner(IrScope *owner) {
    IrScope::setOwner(owner);
    if (alwaysReturn) owner->alwaysReturn = alwaysReturn;
    if (conditionalReturn) owner->conditionalReturn = conditionalReturn;
    for (auto i: instructions) {
        i->setOwner(this);
    }
}
