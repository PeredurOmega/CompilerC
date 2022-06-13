
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ifccParser.
 */
class  ifccListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAxiom(ifccParser::AxiomContext *ctx) = 0;
  virtual void exitAxiom(ifccParser::AxiomContext *ctx) = 0;

  virtual void enterProg(ifccParser::ProgContext *ctx) = 0;
  virtual void exitProg(ifccParser::ProgContext *ctx) = 0;

  virtual void enterStatement(ifccParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ifccParser::StatementContext *ctx) = 0;

  virtual void enterRet(ifccParser::RetContext *ctx) = 0;
  virtual void exitRet(ifccParser::RetContext *ctx) = 0;

  virtual void enterDeclaration(ifccParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(ifccParser::DeclarationContext *ctx) = 0;

  virtual void enterInit(ifccParser::InitContext *ctx) = 0;
  virtual void exitInit(ifccParser::InitContext *ctx) = 0;

  virtual void enterAffectation(ifccParser::AffectationContext *ctx) = 0;
  virtual void exitAffectation(ifccParser::AffectationContext *ctx) = 0;

  virtual void enterVariable(ifccParser::VariableContext *ctx) = 0;
  virtual void exitVariable(ifccParser::VariableContext *ctx) = 0;

  virtual void enterConstant(ifccParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(ifccParser::ConstantContext *ctx) = 0;

  virtual void enterVarexpr(ifccParser::VarexprContext *ctx) = 0;
  virtual void exitVarexpr(ifccParser::VarexprContext *ctx) = 0;


};

