#pragma once

#include "unordered_map"
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

using namespace std;

class CodeGenVisitor : public ifccBaseVisitor {
public:
    antlrcpp::Any visitAxiom(ifccParser::AxiomContext *ctx) override;

    antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

    antlrcpp::Any visitFunction(ifccParser::FunctionContext *ctx) override;

    antlrcpp::Any visitFunctionCall(ifccParser::FunctionCallContext *ctx) override;

    antlrcpp::Any visitParameters(ifccParser::ParametersContext *ctx) override;

    antlrcpp::Any visitParameter(ifccParser::ParameterContext *ctx) override;

    antlrcpp::Any visitBlock(ifccParser::BlockContext *ctx) override;

    antlrcpp::Any visitIfBlock(ifccParser::IfBlockContext *ctx) override;

    antlrcpp::Any visitElseBlock(ifccParser::ElseBlockContext *ctx) override;

    antlrcpp::Any visitWhileBlock(ifccParser::WhileBlockContext *ctx) override;

    antlrcpp::Any visitStatement(ifccParser::StatementContext *ctx) override;

    antlrcpp::Any visitStatementWithoutDeclaration(
            ifccParser::StatementWithoutDeclarationContext *ctx) override;

    antlrcpp::Any
    visitDeclaration(ifccParser::DeclarationContext *ctx) override;

    antlrcpp::Any
    visitRawDeclaration(ifccParser::RawDeclarationContext *ctx) override;

    antlrcpp::Any
    visitAssignment(ifccParser::AssignmentContext *ctx) override;

    antlrcpp::Any
    visitExpAssignment(ifccParser::ExpAssignmentContext *ctx) override;

    antlrcpp::Any visitConstant(ifccParser::ConstantContext *ctx) override;

    antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override;

    antlrcpp::Any visitRet(ifccParser::RetContext *ctx) override;

    antlrcpp::Any visitEmpty(ifccParser::EmptyContext *ctx) override;

    antlrcpp::Any visitAddSub(ifccParser::AddSubContext *ctx) override;

    antlrcpp::Any
    visitTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) override;

    antlrcpp::Any
    visitParenthesis(ifccParser::ParenthesisContext *ctx) override;

    antlrcpp::Any visitUnary(ifccParser::UnaryContext *ctx) override;

    antlrcpp::Any visitCompare(ifccParser::CompareContext *ctx) override;

    antlrcpp::Any visitEqual(ifccParser::EqualContext *ctx) override;

    antlrcpp::Any visitBitwiseAnd(ifccParser::BitwiseAndContext *ctx) override;

    antlrcpp::Any visitBitwiseXor(ifccParser::BitwiseXorContext *ctx) override;

    antlrcpp::Any visitBitwiseOr(ifccParser::BitwiseOrContext *ctx) override;

    antlrcpp::Any visitShift(ifccParser::ShiftContext *ctx) override;

    antlrcpp::Any visitLogicalAnd(ifccParser::LogicalAndContext *ctx) override;

    antlrcpp::Any visitLogicalOr(ifccParser::LogicalOrContext *ctx) override;

private:
    unordered_map<string, int> symbolTable;
    int currentOffset = 0;
    int jumpOffset = 0;
    int finalJump = 0;
    string currentVariable;
    bool hasReturn = false;
};