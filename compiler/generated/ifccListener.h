
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

  virtual void enterBlock(ifccParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ifccParser::BlockContext *ctx) = 0;

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

  virtual void enterTimes(ifccParser::TimesContext *ctx) = 0;
  virtual void exitTimes(ifccParser::TimesContext *ctx) = 0;

  virtual void enterCompare(ifccParser::CompareContext *ctx) = 0;
  virtual void exitCompare(ifccParser::CompareContext *ctx) = 0;

  virtual void enterConstant(ifccParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(ifccParser::ConstantContext *ctx) = 0;

  virtual void enterVarexpr(ifccParser::VarexprContext *ctx) = 0;
  virtual void exitVarexpr(ifccParser::VarexprContext *ctx) = 0;

  virtual void enterVariable(ifccParser::VariableContext *ctx) = 0;
  virtual void exitVariable(ifccParser::VariableContext *ctx) = 0;

  virtual void enterAddsub(ifccParser::AddsubContext *ctx) = 0;
  virtual void exitAddsub(ifccParser::AddsubContext *ctx) = 0;

  virtual void enterUnary(ifccParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(ifccParser::UnaryContext *ctx) = 0;

  virtual void enterParenthesis(ifccParser::ParenthesisContext *ctx) = 0;
  virtual void exitParenthesis(ifccParser::ParenthesisContext *ctx) = 0;

  virtual void enterIfBlock(ifccParser::IfBlockContext *ctx) = 0;
  virtual void exitIfBlock(ifccParser::IfBlockContext *ctx) = 0;

  virtual void enterElseBlock(ifccParser::ElseBlockContext *ctx) = 0;
  virtual void exitElseBlock(ifccParser::ElseBlockContext *ctx) = 0;


};

