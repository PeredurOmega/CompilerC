//
// Created by pauls on 19/06/2022.
//

#include "While.h"
#include "../ir/IrJump.h"
#include "../ir/IrLabel.h"
#include "../ir/IrCompare.h"
#include <sstream>

vector<IrInstruction *> *WhileStatement::linearize() {
    compareLabel = owner->getNewLabel();
    contentLabel = owner->getNewLabel();
    auto *instr = new vector<IrInstruction *>();
    instr->push_back(new IrJump(compareLabel));
    instr->push_back(new IrLabel(".L" + to_string(contentLabel)));
    auto *body = content->linearize();
    instr->insert(instr->end(), body->begin(), body->end());
    instr->push_back(new IrLabel(".L" + to_string(compareLabel)));
    auto *linearizedCompare = compare->linearize();
    instr->insert(instr->end(), linearizedCompare->begin(), linearizedCompare->end());
    instr->push_back(new IrCompare(compare->var));
    instr->push_back(new IrJumpIfNotEqual(contentLabel));
    return instr;
}

void WhileStatement::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    compare->setOwner(owner);
    content->setOwner(owner);
}
