
// Generated from /home/bmayouddup/CLionProjects/CompilerC/compiler/ifcc.g4 by ANTLR 4.10.1

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

  virtual std::any visitStatement(ifccParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInit(ifccParser::InitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAffectation(ifccParser::AffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(ifccParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(ifccParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarexpr(ifccParser::VarexprContext *ctx) override {
    return visitChildren(ctx);
  }


};

