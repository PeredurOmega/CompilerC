//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_DECLARATION_H
#define LIBANTLR4_DECLARATION_H


#include <vector>
#include <unordered_map>
#include "TypeSymbol.h"
#include "Expression.h"

class RawDeclaration {
public:
    explicit RawDeclaration(string *name, Expression *init) : name(name), init(init) {};

    string *name;
    Expression *init;
};

class Declaration : Instruction {
public:
    explicit Declaration(PrimaryType *type): Instruction(), type(type) {};

    void addRawDeclaration(RawDeclaration *rawDec);

    void setOwner(Scope *owner) override;

    vector<IrInstruction *> *linearize() override;

private:
    PrimaryType *type;
    vector<RawDeclaration *> declarations;
};


#endif //LIBANTLR4_DECLARATION_H
