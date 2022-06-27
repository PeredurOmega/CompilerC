//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRPROLOGUE_H
#define LIBANTLR4_IRPROLOGUE_H


#include "IrInstruction.h"

class IrPrologue : public IrInstruction {
public:
    explicit IrPrologue(int stackSize) : IrInstruction(), stackSize(stackSize) {};

    void renderX86(ostream &o) const override;

    void assignMemory() override;

    int stackSize;
};


#endif //LIBANTLR4_IRPROLOGUE_H
