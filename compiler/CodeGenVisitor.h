#pragma once

#include "unordered_map"
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

using namespace std;

class CodeGenVisitor : public ifccBaseVisitor {
public:
    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

    antlrcpp::Any visitStatement(ifccParser::StatementContext *ctx) override;

    antlrcpp::Any
    visitDeclaration(ifccParser::DeclarationContext *ctx) override;

    antlrcpp::Any visitInit(ifccParser::InitContext *ctx) override;

    antlrcpp::Any
    visitAffectation(ifccParser::AffectationContext *ctx) override;

    antlrcpp::Any visitConstant(ifccParser::ConstantContext *ctx) override;

    antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override;

    antlrcpp::Any visitVarexpr(ifccParser::VarexprContext *ctx) override;

    antlrcpp::Any visitRet(ifccParser::RetContext *ctx) override;

    antlrcpp::Any visitAddsub(ifccParser::AddsubContext *ctx) override;

    antlrcpp::Any visitTimes(ifccParser::TimesContext *ctx) override;

    antlrcpp::Any visitParenthesis(ifccParser::ParenthesisContext *ctx) override;

private:
    unordered_map<string, int> symbolTable;
    int currentOffset = 0;
    string currentVariable;

};