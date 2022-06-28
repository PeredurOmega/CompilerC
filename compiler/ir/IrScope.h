//
// Created by pauls on 27/06/2022.
//

#ifndef LIBANTLR4_IRSCOPE_H
#define LIBANTLR4_IRSCOPE_H

#include <string>
#include <unordered_map>
#include "../ast/TypeSymbol.h"

using namespace std;

class IrFunction;

class IrScope {
public:
    explicit IrScope(IrFunction *owner);

    IrFunction *owner;

    IrScope *parent;

    unordered_map<string, int> symbolTable;

    int getOffset(string *varName, PrimaryType *type);

    int insertInitializedVariable(string &varName, PrimaryType *type);

    void insertParameter(string &varName, int offset);

    int insertTempVariable(PrimaryType *type);

    void insertDeclaration(string &varName);

    int currentOffset = 0;

    void syncOffset();

private:
    int incrementOffset(int offset);
};


#endif //LIBANTLR4_IRSCOPE_H
