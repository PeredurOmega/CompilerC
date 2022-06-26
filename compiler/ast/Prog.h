//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_PROG_H
#define LIBANTLR4_PROG_H

#include <vector>
#include "unordered_map"
#include "Scope.h"
#include "Function.h"
#include "Any.h"

using namespace std;

class Prog : Scope {
public:
    explicit Prog(string entry);

    vector<IrInstruction *> *linearize() override;

    void addFunction(Function *function);

    void setOwner(Scope *owner) override;

    int conditionalJump() override;

private:
    string entry;
    vector<Function *> functions;
    int jumpOffset = 0;
    int finalJump = 0;
};


#endif //LIBANTLR4_PROG_H
