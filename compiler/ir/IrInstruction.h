//
// Created by pauls on 24/06/2022.
//

#include "BasicBlock.h"

#ifndef LIBANTLR4_INSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H

using namespace std;

class BasicBlock;

class IrInstruction {
public:

    IrInstruction(BasicBlock *owner) : owner(owner) {};

    BasicBlock *owner;

    virtual void renderX86(ostream &o) const = 0;
};

class Variable {
public:
    Variable(string *name, int offset) : name(name), offset(offset) {};

    ostream &operator<<(ostream &o) const;

    string comment(const string &opType) const;

    string *name;
protected:
    int offset;
};

class OpIrInstruction : public IrInstruction {
public:
    OpIrInstruction(BasicBlock *owner, Variable *to, Variable *left, Variable *right) :
            IrInstruction(owner), to(to), left(left), right(right) {};

protected:
    Variable *to;
    Variable *left;
    Variable *right;
};

class AddIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};


#endif //LIBANTLR4_INSTRUCTION_H
