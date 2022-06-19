//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_TYPESYMBOL_H
#define LIBANTLR4_TYPESYMBOL_H

#include <string>

using namespace std;


class IrType {
public:
    static const int VOID = 3;

    bool operator==(const IrType &other) const;

    bool operator==(int typeId) const;

private:
    int k;

protected:
    explicit IrType(int k) {
        this->k = k;
    }
};

class Void : IrType {
public:
    explicit Void() : IrType(3) {

    }
};

class PrimaryType : IrType {
public:
    static const int INT = 1;
    static const int CHAR = 2;

    explicit PrimaryType(int k) : IrType(k) {}

    static PrimaryType *parse(const string &type);
};

class InvalidType : exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

#endif //LIBANTLR4_TYPESYMBOL_H
