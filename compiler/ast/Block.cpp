//
// Created by pauls on 15/06/2022.
//

#include "Block.h"
#include "../ir/IrScope.h"

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
    return owner->conditionalJump();
}

void Block::linearize(IrFunction *fun) {
    auto* scope = new IrScope(fun);
    if(fun->mainScope == nullptr) {
        fun->mainScope = scope;
    }
    fun->currentScope = scope;
    fun->append(new BasicBlock(&fun->name));
    for (auto *inst: instructions) {
        inst->linearize(fun);
    }
    if (fun->currentScope->parent != nullptr) {
        fun->currentScope = fun->currentScope->parent;
    }
}

void Block::setOwner(Scope *owner) {
    Scope::setOwner(owner);
    if (alwaysReturn) owner->alwaysReturn = alwaysReturn;
    if (conditionalReturn) owner->conditionalReturn = conditionalReturn;
    for (auto i: instructions) {
        i->setOwner(this);
    }
}
