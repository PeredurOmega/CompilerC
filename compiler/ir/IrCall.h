//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRCALL_H
#define LIBANTLR4_IRCALL_H


#include "IrInstruction.h"

class IrCall : public IrInstruction {
public:
    explicit IrCall(string label) : IrInstruction(), label(label) {};

    void renderX86(ostream &o) const override;

    string label;
};


#endif //LIBANTLR4_IRCALL_H
