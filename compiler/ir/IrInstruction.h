//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRINSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H

#include "BasicBlock.h"

using namespace std;

class IrInstruction {
public:

    BasicBlock *owner;

    virtual void renderX86(ostream &o) const = 0;
};

class IrVariable {
public:
    IrVariable(string *name, int offset) : name(name), offset(offset) {};

    ostream &operator<<(ostream &o) const;

    string comment(const string &opType) const;

    string *name;
protected:
    int offset;
};

#endif //LIBANTLR4_INSTRUCTION_H
