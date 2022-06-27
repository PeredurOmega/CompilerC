//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRNOOP_H
#define LIBANTLR4_IRNOOP_H


#include "IrInstruction.h"

class IrNoOp : public IrInstruction {
public:
    using IrInstruction::IrInstruction;

    void assignMemory() override;

    void renderX86(ostream &o) const override;
};

#endif //LIBANTLR4_IRNOOP_H
