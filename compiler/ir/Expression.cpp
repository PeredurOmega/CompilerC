//
// Created by pauls on 16/06/2022.
//

#include "Expression.h"
#include <sstream>
#include <utility>

void Variable::renderX86(ostream &o) const {
    // Nothing to do in a variable
}

Variable::Variable(string name) : Expression(false), name(std::move(name)) {

}

void Variable::affect(IrScope *owner) {
    offset = owner->getOffset(name);
}

void Constant::renderX86(ostream &o) const {
    o << "    movl    $" << value << ", " << offset
      << "(%rbp) #Temp constant" << endl;
}

Constant::Constant(int value) : Expression(false), value(value) {

}

void Constant::affect(IrScope *owner) {
    setOwner(owner);
    offset = owner->insertTempVariable();
}

Return::Return(Expression *expression) : Expression(true),
                                         expression(expression) {

}

void Return::renderX86(ostream &o) const {
    expression->renderX86(o);
    o << "    movl    " << expression->offset << "(%rbp), %eax" << endl;
}

void Return::affect(IrScope *owner) {
    setOwner(owner);
    expression->affect(owner);
}

void Assignment::renderX86(ostream &o) const {
    if (dynamic_cast<Constant *>(expression) != nullptr) {
        // Constant assignment optimization
        o << "    movl    $" << ((Constant *) expression)->value << ", "
          << offset << "(%rbp) #" << to << endl;
        return;
    }
    expression->renderX86(o);
    if (dynamic_cast<Assignment *>(expression) != nullptr) {
        // Case when we recursively assign variables
        o << "    movl    " << expression->offset << "(%rbp), %eax #"
          << ((Assignment *) expression)->to << endl;
        o << "    movl    %eax, " << offset << "(%rbp) #" << to
          << endl;
    } else {
        if (dynamic_cast<Variable *>(expression) != nullptr) {
            o << "    movl    " << expression->offset << "(%rbp), %eax #"
              << ((Variable *) expression)->name << endl;
        } else {
            o << "    movl    " << expression->offset << "(%rbp), %eax #Temp"
              << endl;
        }
        o << "    movl    %eax, " << offset << "(%rbp) #" << to
          << endl;
    }
}

Assignment::Assignment(string to, Expression *expression) :
        Expression(false), to(std::move(to)), expression(expression) {

}

void Assignment::affect(IrScope *owner) {
    setOwner(owner);
    offset = owner->getOffset(to);
    // We don't affect constant for optimization purposes
    if (dynamic_cast<Constant *>(expression) == nullptr) {
        expression->affect(owner);
    }
}

Expression::Expression(bool alwaysReturn) : IrInstruction(alwaysReturn) {

}
