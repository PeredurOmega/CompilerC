//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_DECLARATION_H
#define LIBANTLR4_DECLARATION_H


#include <vector>
#include <set>
#include <unordered_map>
#include "TypeSymbol.h"
#include "Expression.h"

class RawDeclaration {
public:
    explicit RawDeclaration(string *name, Expression *init);

    string *name;
    Expression *init;
};

class Declaration : IrInstruction {
public:
    explicit Declaration(PrimaryType *type);

    void affect(IrScope *owner) override;

    void addRawDeclaration(RawDeclaration *rawDec);

    void renderX86(ostream &o) const override;

    set<string*>* use() override;

    set<string*>* def() override;

    PrimaryType *type;
    vector<RawDeclaration *> declarations;
};


#endif //LIBANTLR4_DECLARATION_H
