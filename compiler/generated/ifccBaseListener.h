
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccListener.h"


/**
 * This class provides an empty implementation of ifccListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ifccBaseListener : public ifccListener {
public:

  virtual void enterAxiom(ifccParser::AxiomContext * /*ctx*/) override { }
  virtual void exitAxiom(ifccParser::AxiomContext * /*ctx*/) override { }

  virtual void enterProg(ifccParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(ifccParser::ProgContext * /*ctx*/) override { }

  virtual void enterStatement(ifccParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ifccParser::StatementContext * /*ctx*/) override { }

  virtual void enterRet(ifccParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(ifccParser::RetContext * /*ctx*/) override { }

  virtual void enterDeclaration(ifccParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(ifccParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterInit(ifccParser::InitContext * /*ctx*/) override { }
  virtual void exitInit(ifccParser::InitContext * /*ctx*/) override { }

  virtual void enterAffectation(ifccParser::AffectationContext * /*ctx*/) override { }
  virtual void exitAffectation(ifccParser::AffectationContext * /*ctx*/) override { }

  virtual void enterTimes(ifccParser::TimesContext * /*ctx*/) override { }
  virtual void exitTimes(ifccParser::TimesContext * /*ctx*/) override { }

  virtual void enterCompare(ifccParser::CompareContext * /*ctx*/) override { }
  virtual void exitCompare(ifccParser::CompareContext * /*ctx*/) override { }

  virtual void enterConstant(ifccParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(ifccParser::ConstantContext * /*ctx*/) override { }

  virtual void enterVarexpr(ifccParser::VarexprContext * /*ctx*/) override { }
  virtual void exitVarexpr(ifccParser::VarexprContext * /*ctx*/) override { }

  virtual void enterVariable(ifccParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(ifccParser::VariableContext * /*ctx*/) override { }

  virtual void enterAddsub(ifccParser::AddsubContext * /*ctx*/) override { }
  virtual void exitAddsub(ifccParser::AddsubContext * /*ctx*/) override { }

  virtual void enterUnary(ifccParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(ifccParser::UnaryContext * /*ctx*/) override { }

  virtual void enterParenthesis(ifccParser::ParenthesisContext * /*ctx*/) override { }
  virtual void exitParenthesis(ifccParser::ParenthesisContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

