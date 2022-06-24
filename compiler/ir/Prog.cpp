//
// Created by pauls on 15/06/2022.
//

#include "Prog.h"

#include <utility>
#include <sstream>

Prog::Prog(string entry) {
    this->entry = std::move(entry);
    this->label = new int(0);
}

void Prog::renderX86(ostream &o) const {
    o << ".globl " << entry << endl; //TODO IMPROVE

    for (Function *function: functions) {
        function->renderX86(o);
    }
}

void Prog::addFunction(Function *function) {
    //TODO CHECK FUNCTION IS NOT ALREADY DECLARED
    functions.push_back(function);
}

void Prog::affect() {
    for (Function *function: functions) {
        function->affect(this);
    }
}

void Prog::affect(IrScope *owner) {
    //TODO CLEAN
}

void Prog::setOwner(IrScope *owner) {
    //TODO CLEAN
}

int Prog::conditionalJump() {
    return -1;
}