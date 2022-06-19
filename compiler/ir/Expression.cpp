//
// Created by pauls on 16/06/2022.
//

#include "Expression.h"
#include <sstream>
#include <utility>
#include <iostream>

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

Expression::Expression() : IrInstruction() {

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
