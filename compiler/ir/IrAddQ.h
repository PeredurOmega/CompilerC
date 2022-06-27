//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRADDQ_H
#define LIBANTLR4_IRADDQ_H

#include "IrInstruction.h"

class IrAddQ : public IrInstruction {
public:
    explicit IrAddQ(int stackSize) : IrInstruction(), stackSize(stackSize) {};

    void renderX86(ostream &o) const override;

    void assignMemory() override;

    int stackSize;
};


#endif //LIBANTLR4_IRADDQ_H
