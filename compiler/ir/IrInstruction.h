//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRINSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H

#include "BasicBlock.h"

using namespace std;

class IrInstruction {
public:

    IrInstruction(BasicBlock *owner) : owner(owner) {};

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

class OpIrInstruction : public IrInstruction {
public:
    OpIrInstruction(BasicBlock *owner, Variable *to, Variable *left,
                    Variable *right) :
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

class SubIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class TimesIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class DivIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class ModuloIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class ShiftRightIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class ShiftLeftIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class LessCompareIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class LessEqualCompareIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class GreatCompareIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class GreatEqualCompareIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class EqualCompareIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class NotEqualCompareIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class BitwiseAndIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class BitwiseXorIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class BitwiseOrIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class LogicalAndIrInstruction : public OpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};


#endif //LIBANTLR4_INSTRUCTION_H
