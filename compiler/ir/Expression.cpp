//
// Created by pauls on 16/06/2022.
//

#include "Expression.h"
#include <sstream>
#include <utility>
#include <iostream>

FunctionCall::FunctionCall(vector<string *> *parameters) : parameters(
        parameters) {

}

void FunctionCall::renderX86(ostream &o) const {

}

void FunctionCall::affect(IrScope *owner) {

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

void Variable::affect(IrScope *owner) {
    setOwner(owner);
    offset = owner->getOffset(name);
}

set<string *> *Variable::use() {
    auto *use = new set<string *>();
    use->insert(&name);
    return use;
}

set<string *> *Variable::def() {
    return Expression::def();
}

void Constant::renderX86(ostream &o) const {
    if (assignTo != nullptr) {
        o << "    movl    $" << value << ", " << offset << "(%rbp) #"
          << *assignTo << endl;
    } else {
        o << "    movl    $" << value << ", " << offset
          << "(%rbp) #Temp constant" << endl;
    }
}

Constant::Constant(int value) : Expression(), value(value) {

}

void Constant::affect(IrScope *owner) {
    setOwner(owner);
    if (assignTo == nullptr) {
        offset = owner->insertTempVariable();
    } else {
        offset = owner->getOffset(*assignTo);
    }
}

set<string *> *Constant::use() {
    return new set<string *>();
}

set<string *> *Constant::def() {
    return new set<string *>();
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

set<string *> *Return::use() {
    return expression->use();
}

set<string *> *Return::def() {
    return expression->def();
}

Expression::Expression() : IrInstruction() {

}

set<string *> *Expression::def() {
    auto *def = new set<string *>();
    if (assignTo != nullptr) {
        def->insert(assignTo);
    }
    return def;
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

set<string *> *VarExpr::def() {
    auto *def = new set<string *>();
    for (auto *d: varNames) {
        def->insert(d);
    }
    return def;
}

set<string *> *VarExpr::use() {
    return expression->use();
}

BlockWrapper::BlockWrapper(IrInstruction *content) : content(content) {

}
