//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRCOMPARE_H
#define LIBANTLR4_IRCOMPARE_H

#include "IrInstruction.h"

class IrCompare : public IrInstruction {
public:
    explicit IrCompare(IrVariable *toCompareTo0) : IrInstruction(), toCompareTo0(toCompareTo0) {};

    void renderX86(ostream &o) const override;

    IrVariable *toCompareTo0;
};


#endif //LIBANTLR4_IRCOMPARE_H
