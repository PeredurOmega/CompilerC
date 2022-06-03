
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

  virtual void enterDeclaration(ifccParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(ifccParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterInit(ifccParser::InitContext * /*ctx*/) override { }
  virtual void exitInit(ifccParser::InitContext * /*ctx*/) override { }

  virtual void enterAffectation(ifccParser::AffectationContext * /*ctx*/) override { }
  virtual void exitAffectation(ifccParser::AffectationContext * /*ctx*/) override { }

  virtual void enterExpression(ifccParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ifccParser::ExpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

