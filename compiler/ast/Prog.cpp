//
// Created by pauls on 15/06/2022.
//

#include "Prog.h"
#include "../ir/IrGlobal.h"
#include "Declaration.h"
#include <sstream>

static const unordered_map<string, Function *> stdFunctions =
        {
                {"putchar", new Function("putchar", (IrType *) new IntType(),
                                         vector<Parameter *>({new Parameter(new IntType(), "char")}))},
        };

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
    if (stdFunctions.find(functionName) != stdFunctions.end()) {
        return stdFunctions.at(functionName)->returnType;
    }
    throw new UndefinedFunction();
}

void Prog::linearize(IrFunction *fun) {

}

void Prog::renderX86(ostream &o) {
    (new IrGlobal(entry))->renderX86(o);
    for (const auto &sDeclaration: *staticVarTable) {
        sDeclaration.second->setOwner(this);
        sDeclaration.second->linearize(nullptr);
    }
    for (auto *function: functions) {
        function->setOwner(this);
        auto *fun = function->linearize();
        fun->assignMemory();
        fun->renderX86(o);
    }
    for (const auto &sDeclaration: *staticVarTable) {
        sDeclaration.second->renderX86(o);
    }
}
