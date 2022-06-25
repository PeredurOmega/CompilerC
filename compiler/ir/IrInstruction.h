//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRINSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H

#include "BasicBlock.h"
#include "IrElement.h"

using namespace std;

class BasicBlock;

class IrInstruction : public IrElement {
public:

    using IrElement::IrElement;

    BasicBlock *owner;

    virtual void renderX86(ostream &o) const = 0;
};

class IrVariable {
public:
    explicit IrVariable(string *name, int offset) : name(name), offset(offset) {};

    friend ostream &operator<<(ostream &o, IrVariable *var);

    virtual string comment(const string &opType) const;

    string *name;
private:
    int offset;
};

class IrRegister : public IrVariable {
public:
    explicit IrRegister(string *name, string *registerName) : IrVariable(name, -1), registerName(registerName) {};

    friend ostream &operator<<(ostream &o, IrRegister *var);

    string comment(const string &opType) const override;

    string *registerName;
};

#endif //LIBANTLR4_IRINSTRUCTION_H
