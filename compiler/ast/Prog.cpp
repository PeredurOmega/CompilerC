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

void Prog::setOwner(Scope *owner) {
    Scope::setOwner(owner);
}

const IrType *Prog::getFunctionType(string functionName) {
    for (Function *function: functions) {
        if (function->name == functionName) {
            return function->returnType;
        }
    }
    throw new UndefinedFunction();
}

void Prog::linearize(IrFunction *fun) {

}

void Prog::renderX86(ostream &o) {
    (new IrGlobal(entry))->renderX86(o);
    for (Function *function: functions) {
        function->setOwner(this);
        auto* fun = function->linearize();
        fun->assignMemory();
        fun->renderX86(o);
    }
}
