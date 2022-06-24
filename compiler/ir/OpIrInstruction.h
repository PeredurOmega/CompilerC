#ifndef LIBANTLR4_OPIREXPRESSION_H
#define LIBANTLR4_OPIREXPRESSION_H

#include "IrInstruction.h"

class OpIrInstruction : public IrInstruction {
public:
    explicit OpIrInstruction(IrVariable *to, IrVariable *left, IrVariable *right)
            : IrInstruction(), to(to), left(left), right(right) {};

protected:
    IrVariable *to;
    IrVariable *left;
    IrVariable *right;
};

class AddIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class SubIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class TimesIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class DivIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class ModuloIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class ShiftRightIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class ShiftLeftIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class LessCompareIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class LessEqualCompareIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class GreatCompareIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class GreatEqualCompareIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class EqualCompareIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class NotEqualCompareIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class BitwiseAndIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class BitwiseXorIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class BitwiseOrIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class LogicalAndIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

class LogicalOrIrInstruction : public OpIrInstruction {
public:
    using OpIrInstruction::OpIrInstruction;

    void renderX86(ostream &o) const override;
};

#endif //LIBANTLR4_OPIREXPRESSION_H
