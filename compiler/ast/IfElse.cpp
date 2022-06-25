//
// Created by pauls on 17/06/2022.
//

#include "IfElse.h"
#include "../ir/IrCompare.h"
#include "../ir/IrJump.h"
#include "../ir/IrLabel.h"
#include <sstream>


vector<IrInstruction *> *IfStatement::linearize() {
    auto *instr = compare->linearize();
    instr->push_back(new IrCompare(compare->var));

    firstLabel = owner->getNewLabel();
    if (finalLabel == 0) finalLabel = owner->getNewLabel();

    int nextLabel;
    if (elseStatement != nullptr) nextLabel = elseStatement->label;
    else nextLabel = finalLabel;
    instr->push_back(new IrJumpIfEqual(nextLabel));

    auto *body = content->linearize();
    instr->insert(instr->end(), body->begin(), body->end());

    if (elseStatement != nullptr) {
        elseStatement->finalLabel = finalLabel;
        instr->push_back(new IrJump(finalLabel));
        auto *elseBlock = content->linearize();
        instr->insert(instr->end(), elseBlock->begin(), elseBlock->end());
    }

    // Closing the branch
    if (finalLabel == firstLabel + 1) {
        instr->push_back(new IrLabel(".L" + to_string(finalLabel)));
    }
    return nullptr;
}

void IfStatement::setOwner(IrScope *owner) {
    Instruction::setOwner(owner);
    compare->setOwner(owner);
    content->setOwner(owner);
    if (elseStatement != nullptr) elseStatement->setOwner(owner);
}

vector<IrInstruction *> *ElseStatement::linearize() {
    auto *instr = new vector<IrInstruction *>();
    label = owner->getNewLabel();
    instr->push_back(new IrLabel(".L" + to_string(label)));
    if (dynamic_cast<IfStatement *>(content) != nullptr) {
        ((IfStatement *) content)->finalLabel = finalLabel;
    }
    auto *body = content->linearize();
    instr->insert(instr->end(), body->begin(), body->end());
    return instr;
}

void ElseStatement::setOwner(IrScope *owner) {
    Instruction::setOwner(owner);
    content->setOwner(owner);
}
