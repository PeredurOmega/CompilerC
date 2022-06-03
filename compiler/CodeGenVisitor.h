#pragma once

#include "unordered_map"
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

using namespace std;

class  CodeGenVisitor : public ifccBaseVisitor {
public:
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;
    virtual antlrcpp::Any visitStatement(ifccParser::StatementContext *ctx) override ;
    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override ;
    virtual antlrcpp::Any visitInit(ifccParser::InitContext *ctx) override ;
    virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override ;
    virtual antlrcpp::Any visitExpression(ifccParser::ExpressionContext *ctx) override ;
private:
    unordered_map<string, string> variables;
};