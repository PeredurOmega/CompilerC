//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRRETURN_H
#define LIBANTLR4_IRRETURN_H


#include "IrInstruction.h"

class IrReturn : public IrInstruction {
public:
    explicit IrReturn(IrVariable *from) : IrInstruction(), from(from) {};

    void renderX86(ostream &o) const override;

    void assignMemory() override;

    IrVariable *from;
};


#endif //LIBANTLR4_IRRETURN_H
