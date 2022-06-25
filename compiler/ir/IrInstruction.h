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
    explicit IrVariable(string *name, int offset) : name(name), offset(offset) {};

    virtual ostream &operator<<(ostream &o) const;

    virtual string comment(const string &opType) const;

    string *name;
private:
    int offset;
};

class IrRegister : public IrVariable {
public:
    explicit IrRegister(string *name, string *registerName) : name(name), registerName(registerName) {};

    ostream &operator<<(ostream &o) const override;

    string comment(const string &opType) const override;

    string *name;

    string *registerName;
};

#endif //LIBANTLR4_IRINSTRUCTION_H
