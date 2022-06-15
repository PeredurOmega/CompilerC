//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_PROG_H
#define LIBANTLR4_PROG_H

#include <vector>
#include "unordered_map"
#include "IrScope.h"
#include "Function.h"
#include "Any.h"

using namespace std;

class Prog : IrScope {
public:
    explicit Prog(string entry);

    void renderX86(ostream &o) const override;

    void addFunction(Function *function);

private:
    string entry;
    vector<Function *> functions;
    int jumpOffset = 0;
    int finalJump = 0;
};


#endif //LIBANTLR4_PROG_H
