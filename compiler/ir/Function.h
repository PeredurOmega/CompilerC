//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_FUNCTION_H
#define LIBANTLR4_FUNCTION_H


#include <vector>
#include "IrElement.h"
#include "Block.h"
#include "TypeSymbol.h"

class Function : Block {
public:
    //TODO HANDLE PARAMETERS
    explicit Function(string name, const IrType *returnType);

    void renderX86(ostream &o) const override;

    void setBlock(Block *block);

private:
    const string MAIN = "main";
    const IrType *returnType;
    const string name;
    bool alwaysReturn = false;
    //vector<IrInstr> blocks;
};


#endif //LIBANTLR4_FUNCTION_H
