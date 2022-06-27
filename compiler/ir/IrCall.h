//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRCALL_H
#define LIBANTLR4_IRCALL_H


#include <utility>

#include "IrInstruction.h"

class IrCall : public IrInstruction {
public:
    explicit IrCall(string label) : IrInstruction(), label(std::move(label)) {};

    void renderX86(ostream &o) const override;

    void assignMemory() override;

    string label;
};


#endif //LIBANTLR4_IRCALL_H
