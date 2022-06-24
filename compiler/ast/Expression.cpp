//
// Created by pauls on 16/06/2022.
//

#include "Expression.h"
#include "../ir/IrConstant.h"
#include "../ir/IrReturn.h"
#include "../ir/IrJump.h"
#include "../ir/IrCopy.h"
#include <sstream>
#include <utility>
#include <iostream>

FunctionCall::FunctionCall(string name, vector<Expression *> *arguments) : name(
        std::move(name)), arguments(arguments) {}

void FunctionCall::renderX86(ostream &o) const {
    vector<string> registersName = {"%edi", "%esi", "%edx", "%ecx", "%r8d",
                                    "%r9d"};
    for (int i = (int) arguments->size() - 1; i >= 0; --i) {
        Expression *expression = (*arguments)[i];
        expression->renderX86(o);
        if (i < 6) {
            o << "    movl    " << expression->offset
              << "(%rbp), " + registersName[i] << endl;
        } else {
            o << "    pushq    " << expression->offset << "(%rbp)" << endl;
        }
    }
    o << "    call    " << name << endl;
    if (arguments->size() > 6) {
        o << "    addq    $" << 8 * (arguments->size() - 6) << ", %rsp" << endl;
    }
    o << "    movl    %eax, " << offset << "(%rbp) #";
    if (assignTo != nullptr) {
        o << *assignTo;
    } else {
        o << "Temp operation result '>>'";
    }
    o << endl;
}

void FunctionCall::affect(IrScope *owner) {
    setOwner(owner);
    for (auto expression: *arguments) {
        expression->affect(owner);
    }
    if (assignTo == nullptr) {
        offset = owner->insertTempVariable();
    } else {
        offset = owner->getOffset(*assignTo);
    }
}

vector<IrInstruction *> *Variable::linearize() {
    var = new IrVariable(&name, owner->getOffset(&name));
    return new vector<IrInstruction *>();
}

vector<IrInstruction *> *Constant::linearize() {
    auto *inst = new vector<IrInstruction *>();
    var = new IrVariable(nullptr, owner->insertTempVariable());
    auto *c = new IrConstant(owner->basicBlock(), var, value);
    inst->push_back(c);
    return inst;
}

vector<IrInstruction *> *Return::linearize() {
    auto *inst = expression->linearize();
    inst->push_back(new IrReturn(expression->var));
    int conditionalJump = owner->conditionalJump();
    if (conditionalJump != -1) {
        inst->push_back(new IrJump(conditionalJump));
    }
    return inst;
}

vector<IrInstruction *> *VarExpr::linearize() {
    auto *inst = expression->linearize();
    auto lastVar = varNames.front();
    auto *prevVar = expression->var;
    for (int i = (int) varNames.size() - 1; i >= 0; i--) {
        auto *to = new IrVariable(varNames[i], owner->getOffset(varNames[i]));
        auto *copy = new IrCopy(prevVar, to);
        prevVar = to;
        inst->push_back(copy);
    }
    var = new IrVariable(lastVar, owner->getOffset(lastVar));
    return inst;
}