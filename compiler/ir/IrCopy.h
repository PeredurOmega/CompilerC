//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_IRCOPY_H
#define LIBANTLR4_IRCOPY_H


#include "IrInstruction.h"

class IrCopy : public IrInstruction {
public:
    explicit IrCopy(IrVariable *from, IrVariable* to) : IrInstruction(), from(from), to(to) {};

    void assignMemory() override;

    void renderX86(ostream &o) const override;

    IrVariable *from;
    IrVariable *to;
};


#endif //LIBANTLR4_IRCOPY_H
