//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRLABEL_H
#define LIBANTLR4_IRLABEL_H

#include "IrInstruction.h"

class IrLabel : public IrInstruction {
public:
    explicit IrLabel(string label) : IrInstruction(), label(std::move(label)) {};

    void renderX86(ostream &o) const override;

    void assignMemory() override;

    string label;
};


#endif //LIBANTLR4_IRLABEL_H
