//
// Created by pauls on 27/06/2022.
//

#ifndef LIBANTLR4_IRSCOPE_H
#define LIBANTLR4_IRSCOPE_H

#include <string>
#include <unordered_map>

using namespace std;

class IrFunction;

class IrScope {
public:
    explicit IrScope(IrFunction *owner);

    IrFunction *owner;

    IrScope *parent;

    unordered_map<string, int> symbolTable;

    int getOffset(string *varName);

    int insertInitializedVariable(string &varName);

    void insertParameter(string &varName, int offset);

    int insertTempVariable();

    int incrementOffset(int offset);

    void insertDeclaration(string &varName);

    int currentOffset = 0;
};


#endif //LIBANTLR4_IRSCOPE_H
