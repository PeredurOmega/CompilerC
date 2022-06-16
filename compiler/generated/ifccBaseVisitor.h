
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual std::any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(ifccParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(ifccParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(ifccParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(ifccParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(ifccParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfBlock(ifccParser::IfBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseBlock(ifccParser::ElseBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRet(ifccParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRawDeclaration(ifccParser::RawDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(ifccParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompare(ifccParser::CompareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(ifccParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShift(ifccParser::ShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseXor(ifccParser::BitwiseXorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAnd(ifccParser::LogicalAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSub(ifccParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary(ifccParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseAnd(ifccParser::BitwiseAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesis(ifccParser::ParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqual(ifccParser::EqualContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarExpr(ifccParser::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(ifccParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseOr(ifccParser::BitwiseOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOr(ifccParser::LogicalOrContext *ctx) override {
    return visitChildren(ctx);
  }


};

