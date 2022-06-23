//
// Created by pauls on 15/06/2022.
//

#include "Function.h"

#include <utility>
#include <sstream>

using namespace std;

Function::Function(string name, const IrType *returnType, const vector<Parameter *>& parameters) : returnType(returnType), name(std::move(name)), parameters(parameters) {
    int offset = 16;
    if(!parameters.empty()) {
        this->name += "(";
    }
    for (auto parameter : parameters) {
        insertParameter(parameter->name, offset);
        offset += 8;
        this->name += PrimaryType::text(parameter->type) + ",";
    }
    if(!parameters.empty()) {
        this->name += ")";
    }
    int replaceOffset = (int)this->name.find(",)");
    if(replaceOffset != -1) {
        this->name.replace(replaceOffset, 2, ")");
    }
}

void Function::renderX86(ostream &o) const {
    o << " " << name << ":" << endl
      << "    pushq   %rbp" << endl
      << "    movq    %rsp, %rbp" << endl;

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

    o << "    popq %rbp" << endl
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
    Block::affect(owner);
    if (conditionalReturn) {
        endLabel = owner->getNewLabel();
    }
}

Parameter::Parameter(PrimaryType *type, string name) : type(type), name(std::move(name)) { }
