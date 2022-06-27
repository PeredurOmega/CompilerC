#ifndef LIBANTLR4_UNARYOPIRINSTRUCTION_H
#define LIBANTLR4_UNARYOPIRINSTRUCTION_H

#include "IrInstruction.h"

class UnaryOpIrInstruction : public IrInstruction {
public:
    UnaryOpIrInstruction(IrVariable *to, IrVariable *right) : to(to), right(right) {};

    void assignMemory() override;

protected:
    IrVariable *to;
    IrVariable *right;
};

class MinusUnaryIrInstruction : public UnaryOpIrInstruction {
public:
    using UnaryOpIrInstruction::UnaryOpIrInstruction;

    void renderX86(ostream &o) const override;
};

class NotUnaryIrInstruction : public UnaryOpIrInstruction {
public:
    using UnaryOpIrInstruction::UnaryOpIrInstruction;

    void renderX86(ostream &o) const override;
};

class BitwiseNotUnaryIrInstruction : public UnaryOpIrInstruction {
public:
    using UnaryOpIrInstruction::UnaryOpIrInstruction;

    void renderX86(ostream &o) const override;
};

#endif //LIBANTLR4_UNARYOPIRINSTRUCTION_H
