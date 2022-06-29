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
        usedFunction->insert(pair(functionName, true));
        return stdFunctions.at(functionName)->returnType;
    }
    throw new UndefinedFunction();
}

void Prog::linearize(IrFunction *fun) {

}

void Prog::renderX86(ostream &o) {
    usedFunction->insert(pair(entry, true));
    for (const auto &sDeclaration: staticVarTable) {
        sDeclaration.second->setOwner(this);
        sDeclaration.second->linearize(nullptr);
    }
    vector<IrFunction *> irFunctions;
    for (auto *function: functions) {
        function->setOwner(this);
        auto *fun = function->linearize();
        fun->assignMemory();
        irFunctions.push_back(fun);
    }
    warnAboutUnusedFunctions();
    warnAboutUnusedVariables();

    vector<StaticDeclaration *> staticDeclarations;
    for (const auto &sDeclaration: staticVarTable) {
        staticDeclarations.push_back(sDeclaration.second);
    }
    if (!staticVarTable.empty()) {
        (new IrGlobal(*staticDeclarations[0]->name))->renderX86(o);
        o << "    .data" << endl;
        o << "    .align 4" << endl;
    } else {
        (new IrGlobal(entry))->renderX86(o);
    }
    for (int i = 0; i < (int) staticDeclarations.size(); i++) {
        staticDeclarations[i]->renderX86(o);
        if (i == (int) staticDeclarations.size() - 1) {
            o << "    .text" << endl;
            o << "    .globl   " << entry << endl;
        } else {
            o << "    .globl   " << *staticDeclarations[i + 1]->name << endl;
            o << "    .align 4" << endl;
        }
    }
    for (auto *fun: irFunctions) {
        fun->renderX86(o);
    }
}

void Prog::warnAboutUnusedFunctions() {
    for (auto *function: functions) {
        if (usedFunction->find(function->name) == usedFunction->end()) {
            cerr << "Warning: function " << function->name << " is not used." << endl;
        }
    }
}

IrVariable *Prog::getStaticIrVariable(string *varName) {
    usedVar.insert(pair(*varName, true));
    if (staticVarTable.find(*varName) != staticVarTable.end()) {
        return new IrStaticVariable(varName, staticVarTable.at(*varName)->type);
    } else {
        return nullptr;
    }
}

PrimaryType *Prog::declareStaticVariable(StaticDeclaration *sDeclaration) {
    if (staticVarTable.find(*sDeclaration->name) != staticVarTable.end()) {
        AlreadyDeclaredVariable e = AlreadyDeclaredVariable();
        cerr << e.what() << " '" << *sDeclaration->name << "'";//TODO
        throw e;
    } else {
        staticVarTable.insert(pair(*(sDeclaration->name), sDeclaration));
        return sDeclaration->type;
    }
}

void Prog::warnAboutUnusedVariables() {
    Scope::warnAboutUnusedVariables();
    for (auto &it: staticVarTable) {
        if (usedVar.find(it.first) == usedVar.end()) {
            cerr << "Warning: unused static/global variable '" << it.first << "'." << endl;
        }
    }
}
