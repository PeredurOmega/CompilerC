#ifndef LIBANTLR4_UNARYOPIRINSTRUCTION_H
#define LIBANTLR4_UNARYOPIRINSTRUCTION_H

#include "IrInstruction.h"

class UnaryOpIrInstruction : public IrInstruction {
public:
    UnaryOpIrInstruction(BasicBlock *owner, IrVariable *to, IrVariable *left,
                    IrVariable *right) :
            IrInstruction(owner), to(to), right(right) {};

protected:
    IrVariable *to;
    IrVariable *right;
};

class MinusUnaryIrInstruction : public UnaryOpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class NotUnaryIrInstruction : public UnaryOpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

class BitwiseNotUnaryIrInstruction : public UnaryOpIrInstruction {
public:
    void renderX86(ostream &o) const override;
};

#endif //LIBANTLR4_UNARYOPIRINSTRUCTION_H
