//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRINSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H

#include "BasicBlock.h"
#include "IrElement.h"
#include "../ast/TypeSymbol.h"
#include "IrScope.h"

using namespace std;

class BasicBlock;

class IrInstruction : public IrElement {
public:

    using IrElement::IrElement;

    BasicBlock *owner;

    IrScope *scope;

    virtual void renderX86(ostream &o) const = 0;

    virtual void assignMemory() = 0;
};

class IrVariable {
public:
    explicit IrVariable(string *name, PrimaryType *type) : name(name), type(type) {};

    friend ostream &operator<<(ostream &o, IrVariable *var);

    virtual string comment(const string &opType) const;

    virtual void assignMemory(IrScope *scope);

    string *name;

    int offset = -1;

    PrimaryType *type;
};


class IrTempVariable: public IrVariable {
public:
    explicit IrTempVariable(PrimaryType *type) : IrVariable(new string("Temp"), type) {};

    friend ostream &operator<<(ostream &o, IrVariable *var);

    virtual void assignMemory(IrScope *scope);
};

/*
class IrArgument : IrVariable {
public:
    explicit IrArgument(string *name, PrimaryType *type, int offset) : IrVariable(name, type), offset(offset) {};

    friend ostream &operator<<(ostream &o, IrArgument *var);

    int offset;

    virtual void assignMemory() = 0;
};*/

class IrRegister : public IrVariable {
public:
    explicit IrRegister(string *name, string *registerName, PrimaryType *type)
            : IrVariable(name, type), registerName(registerName) {};

    friend ostream &operator<<(ostream &o, IrRegister *var);

    void assignMemory(IrScope* scope) override;

    string *registerName;
};

#endif //LIBANTLR4_IRINSTRUCTION_H
