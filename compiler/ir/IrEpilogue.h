//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IREPILOGUE_H
#define LIBANTLR4_IREPILOGUE_H


#include "IrInstruction.h"

class IrEpilogue : public IrInstruction {
public:
    explicit IrEpilogue(int stackSize) : IrInstruction(), stackSize(stackSize) {};

    void renderX86(ostream &o) const override;

    int stackSize;
};



#endif //LIBANTLR4_IREPILOGUE_H
