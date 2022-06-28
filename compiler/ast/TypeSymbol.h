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

class PrimaryType : public IrType {
public:
    static const int INT = 1;
    static const int CHAR = 2;

    explicit PrimaryType(int k, int offset) : IrType(k), offset(offset) {}

    static PrimaryType *parse(const string &type);

    static string text(PrimaryType *type);

    int offset;
};

class IntType : public PrimaryType {
public:
    explicit IntType() : PrimaryType(PrimaryType::INT, 4) {};
};

class CharType : public PrimaryType {
public:
    //TODO OFFSET SHOULD BE 4 IN THE FUTURE
    explicit CharType() : PrimaryType(PrimaryType::CHAR, 4) {};
};

class InvalidType : exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

#endif //LIBANTLR4_TYPESYMBOL_H
