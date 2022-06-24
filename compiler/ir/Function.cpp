//
// Created by pauls on 15/06/2022.
//

#include "Function.h"

#include <utility>
#include <sstream>
#include <iostream>

using namespace std;

Function::Function(string name, const IrType *returnType, const vector<Parameter *>& parameters) : returnType(returnType), name(std::move(name)), parameters(parameters) {

}

void Function::renderX86(ostream &o) const {
    int stackShift = (int)((symbolTable.size()/4)+1)*32;

    o << " " << name << ":" << endl
      << "    pushq   %rbp" << endl
      << "    movq    %rsp, %rbp" << endl
      << "    subq    $" << stackShift << ", %rsp" << endl;

    for (const auto& r : registers) {
        o << "    movl    " << get<0>(r) << ", " << get<2>(r) << "(%rbp)" << " #" << get<1>(r) << endl;
    }

    Block::renderX86(o);

    if (!alwaysReturn) {
        if (name == MAIN && *returnType == PrimaryType::INT) {
            o << "    movl    $0, %eax" << endl;
        } else {
            o << "    nop" << endl;
        }
    }
    if (conditionalReturn) {
        o << ".L" << endLabel << ":" << endl;
    }

    o << "    addq    $" << stackShift << ", %rsp" << endl
      << "    popq    %rbp" << endl
      << "    ret" << endl;
}

void Function::setBlock(Block *block) {
    block->attachTo(this);
}

int Function::conditionalJump() {
    if (conditionalReturn) return endLabel;
    else return -1;
}

void Function::affect(IrScope *owner) {
    setOwner(owner);
    vector<string> registersName = {"%edi" , "%esi", "%edx", "%ecx", "%r8d", "%r9d"};
    int offset = 16;
    for (unsigned int i = 0; i < parameters.size(); ++i) {
        Parameter* parameter = parameters[i];
        if (i < 6) {
            registers.emplace_back(registersName[i], parameter->name, insertInitializedVariable(parameter->name));
        } else {
            insertParameter(parameter->name, offset);
            offset += 8;
        }
    }
    Block::affect(owner);
    if (conditionalReturn) {
        endLabel = owner->getNewLabel();
    }
}

Parameter::Parameter(PrimaryType *type, string name) : type(type), name(std::move(name)) { }
