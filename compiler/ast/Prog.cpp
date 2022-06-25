//
// Created by pauls on 15/06/2022.
//

#include "Prog.h"
#include "../ir/IrGlobal.h"

#include <utility>
#include <sstream>

Prog::Prog(string entry) {
    this->entry = std::move(entry);
    this->label = new int(0);
}

void Prog::addFunction(Function *function) {
    //TODO CHECK FUNCTION IS NOT ALREADY DECLARED
    functions.push_back(function);
}

int Prog::conditionalJump() {
    return -1;
}

vector<IrInstruction *> *Prog::linearize() {
    auto *instr = new vector<IrInstruction *>();
    instr->push_back(new IrGlobal(entry));
    for (Function *function: functions) {
        function->setOwner(this);
        auto *l = function->linearize();
        instr->insert(instr->end(), l->begin(), l->end());
    }
    return instr;
}

void Prog::setOwner(IrScope *owner) {
    IrScope::setOwner(owner);
}
