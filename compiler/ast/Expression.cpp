//
// Created by pauls on 16/06/2022.
//

#include "Expression.h"
#include "../ir/IrConstant.h"
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

void Variable::renderX86(ostream &o) const {
    if (assignTo != nullptr) {
        o << "    movl    " << offset << "(%rbp), %eax #" << name << endl;
        o << "    movl    %eax, " << owner->getOffset(*assignTo) << "(%rbp) #"
          << *assignTo << endl;
    } else {
        // Nothing to do in a variable
    }
}

Variable::Variable(string name) : Expression(), name(std::move(name)) {

}

vector<IrInstruction *> *Variable::linearize() {
    var = new IrVariable(&name, owner->getOffset(&name));
    return new vector<IrInstruction *>();
}

vector<IrInstruction *> *Constant::linearize() {
    auto *inst = new vector<IrInstruction *>();
    var = new IrVariable(nullptr, owner->insertTempVariable());
    auto *c = new IrConstant(owner->getBasicBlock(), var, value);
    inst->push_back(c);
    return inst;
}

void Constant::affect(IrScope *owner) {
    setOwner(owner);
    if (assignTo == nullptr) {
        offset = owner->insertTempVariable();
    } else {
        offset = owner->getOffset(*assignTo);
    }
}

Return::Return(Expression *expression) : Expression(), expression(expression) {
    alwaysReturn = true;
}

void Return::renderX86(ostream &o) const {
    expression->renderX86(o);
    o << "    movl    " << expression->offset << "(%rbp), %eax" << endl;
    int conditionalJump = owner->conditionalJump();
    if (conditionalJump != -1) {
        o << "    jmp      .L" << conditionalJump << endl;
    }
}

void Return::affect(IrScope *owner) {
    setOwner(owner);
    expression->affect(owner);
}

Expression::Expression() : Instruction() {

}

VarExpr::VarExpr(vector<string *> *varNames, Expression *expression) :
        Expression(), varNames(*varNames), expression(expression) {

}

void VarExpr::affect(IrScope *owner) {
    setOwner(owner);
    expression->affect(owner);
    for (auto v: varNames) {
        offsets.push_back(owner->getOffset(*v));
    }
    offset = offsets.front();
}

void VarExpr::renderX86(ostream &o) const {
    expression->renderX86(o);
    for (int i = (int) offsets.size() - 1; i > 0; i--) {
        o << "    movl    " << offsets[i] << "(%rbp), %eax #" << *varNames[i]
          << endl;
        o << "    movl    %eax, " << offsets[i - 1] << "(%rbp) #"
          << *varNames[i - 1] << endl;
    }
}
