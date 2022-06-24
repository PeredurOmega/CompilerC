//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRJUMP_H
#define LIBANTLR4_IRJUMP_H


#include "IrInstruction.h"

class IrJump : public IrInstruction {
public:
    explicit IrJump(int toLabel) : IrInstruction(), toLabel(toLabel) {};

    void renderX86(ostream &o) const override;

    int toLabel;
};


#endif //LIBANTLR4_IRJUMP_H
