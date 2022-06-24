//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRCONSTANT_H
#define LIBANTLR4_IRCONSTANT_H


#include "IrInstruction.h"

class IrConstant : public IrInstruction {
public:
    explicit IrConstant(BasicBlock *owner, int value, IrVariable *to) :
            IrInstruction(owner), value(value), to(to) {};

    void renderX86(ostream &o) const override;

    int value;
    IrVariable *to;
};


#endif //LIBANTLR4_IRCONSTANT_H
