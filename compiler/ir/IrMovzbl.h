//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRMOVZBL_H
#define LIBANTLR4_IRMOVZBL_H

#include "IrInstruction.h"

class IrMobzbl : public IrInstruction {
public:
    explicit IrMobzbl(IrVariable *from, IrVariable *to) : IrInstruction(), from(from), to(to) {};

    void renderX86(ostream &o) const override;

    void assignMemory() override;

    IrVariable *from;
    IrVariable *to;
};

#endif //LIBANTLR4_IRMOVZBL_H
