//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_IRELEMENT_H
#define LIBANTLR4_IRELEMENT_H

#include <string>

using namespace std;

class IrElement {
public:
    explicit IrElement() = default;

    virtual void renderX86(ostream &o) const = 0;
};


#endif //LIBANTLR4_IRELEMENT_H
