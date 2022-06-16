//
// Created by pauls on 15/06/2022.
//

#include "Function.h"

#include <utility>
#include <sstream>

using namespace std;

Function::Function(string name, const IrType *returnType) :
        returnType(returnType), name(std::move(name)) {
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

    o << "    popq %rbp" << endl
      << "    ret" << endl;
}

void Function::setBlock(Block *block) {
    alwaysReturn = block->alwaysReturn;
    block->attachTo(this);
}
