//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_IRSCOPE_H
#define LIBANTLR4_IRSCOPE_H

#include <unordered_map>
#include "IrElement.h"

using namespace std;

class IrScope: IrElement {
protected:
    unordered_map<string, int> symbolTable;
    int currentOffset = 0;
};


#endif //LIBANTLR4_IRSCOPE_H
