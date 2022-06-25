//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRGLOBAL_H
#define LIBANTLR4_IRGLOBAL_H

#include <utility>

#include "IrInstruction.h"

class IrGlobal : public IrInstruction {
public:
    explicit IrGlobal(string entry) : IrInstruction(), entry(std::move(entry)) {};

    void renderX86(ostream &o) const override;

    string entry;
};

#endif //LIBANTLR4_IRGLOBAL_H
