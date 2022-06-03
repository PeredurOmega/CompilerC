
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1


#include "ifccListener.h"
#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct IfccParserStaticData final {
  IfccParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccParserStaticData(const IfccParserStaticData&) = delete;
  IfccParserStaticData(IfccParserStaticData&&) = delete;
  IfccParserStaticData& operator=(const IfccParserStaticData&) = delete;
  IfccParserStaticData& operator=(IfccParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag ifccParserOnceFlag;
IfccParserStaticData *ifccParserStaticData = nullptr;

void ifccParserInitialize() {
  assert(ifccParserStaticData == nullptr);
  auto staticData = std::make_unique<IfccParserStaticData>(
    std::vector<std::string>{
      "axiom", "prog", "statement", "declaration", "init", "affectation", 
      "expression"
    },
    std::vector<std::string>{
      "", "'main'", "'('", "')'", "'{'", "';'", "'}'", "','", "'='", "'return'", 
      "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "RETURN", "TYPE", "CONST", "VAR", 
      "COMMENT", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,15,70,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,23,8,1,10,1,12,1,26,9,1,1,1,1,1,1,1,1,
  	1,1,1,1,2,1,2,3,2,35,8,2,1,3,1,3,1,3,3,3,40,8,3,1,3,1,3,1,3,3,3,45,8,
  	3,5,3,47,8,3,10,3,12,3,50,9,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,
  	1,5,1,6,1,6,1,6,1,6,1,6,3,6,68,8,6,1,6,0,0,7,0,2,4,6,8,10,12,0,0,69,0,
  	14,1,0,0,0,2,16,1,0,0,0,4,34,1,0,0,0,6,36,1,0,0,0,8,53,1,0,0,0,10,57,
  	1,0,0,0,12,67,1,0,0,0,14,15,3,2,1,0,15,1,1,0,0,0,16,17,5,10,0,0,17,18,
  	5,1,0,0,18,19,5,2,0,0,19,20,5,3,0,0,20,24,5,4,0,0,21,23,3,4,2,0,22,21,
  	1,0,0,0,23,26,1,0,0,0,24,22,1,0,0,0,24,25,1,0,0,0,25,27,1,0,0,0,26,24,
  	1,0,0,0,27,28,5,9,0,0,28,29,5,11,0,0,29,30,5,5,0,0,30,31,5,6,0,0,31,3,
  	1,0,0,0,32,35,3,6,3,0,33,35,3,10,5,0,34,32,1,0,0,0,34,33,1,0,0,0,35,5,
  	1,0,0,0,36,39,5,10,0,0,37,40,3,8,4,0,38,40,5,12,0,0,39,37,1,0,0,0,39,
  	38,1,0,0,0,40,48,1,0,0,0,41,44,5,7,0,0,42,45,3,8,4,0,43,45,5,12,0,0,44,
  	42,1,0,0,0,44,43,1,0,0,0,45,47,1,0,0,0,46,41,1,0,0,0,47,50,1,0,0,0,48,
  	46,1,0,0,0,48,49,1,0,0,0,49,51,1,0,0,0,50,48,1,0,0,0,51,52,5,5,0,0,52,
  	7,1,0,0,0,53,54,5,12,0,0,54,55,5,8,0,0,55,56,3,12,6,0,56,9,1,0,0,0,57,
  	58,5,12,0,0,58,59,5,8,0,0,59,60,3,12,6,0,60,61,5,5,0,0,61,11,1,0,0,0,
  	62,68,5,12,0,0,63,68,5,11,0,0,64,65,5,12,0,0,65,66,5,8,0,0,66,68,3,12,
  	6,0,67,62,1,0,0,0,67,63,1,0,0,0,67,64,1,0,0,0,68,13,1,0,0,0,6,24,34,39,
  	44,48,67
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifccParserStaticData = staticData.release();
}

}

ifccParser::ifccParser(TokenStream *input) : ifccParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ifccParser::ifccParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ifccParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ifccParserStaticData->atn, ifccParserStaticData->decisionToDFA, ifccParserStaticData->sharedContextCache, options);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

const atn::ATN& ifccParser::getATN() const {
  return *ifccParserStaticData->atn;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return ifccParserStaticData->ruleNames;
}

const dfa::Vocabulary& ifccParser::getVocabulary() const {
  return ifccParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccParser::getSerializedATN() const {
  return ifccParserStaticData->serializedATN;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}

void ifccParser::AxiomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAxiom(this);
}

void ifccParser::AxiomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAxiom(this);
}


std::any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    prog();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ProgContext::TYPE() {
  return getToken(ifccParser::TYPE, 0);
}

tree::TerminalNode* ifccParser::ProgContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

tree::TerminalNode* ifccParser::ProgContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

std::vector<ifccParser::StatementContext *> ifccParser::ProgContext::statement() {
  return getRuleContexts<ifccParser::StatementContext>();
}

ifccParser::StatementContext* ifccParser::ProgContext::statement(size_t i) {
  return getRuleContext<ifccParser::StatementContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}

void ifccParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ifccParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    match(ifccParser::TYPE);
    setState(17);
    match(ifccParser::T__0);
    setState(18);
    match(ifccParser::T__1);
    setState(19);
    match(ifccParser::T__2);
    setState(20);
    match(ifccParser::T__3);
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::TYPE

    || _la == ifccParser::VAR) {
      setState(21);
      statement();
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(27);
    match(ifccParser::RETURN);
    setState(28);
    match(ifccParser::CONST);
    setState(29);
    match(ifccParser::T__4);
    setState(30);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ifccParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::DeclarationContext* ifccParser::StatementContext::declaration() {
  return getRuleContext<ifccParser::DeclarationContext>(0);
}

ifccParser::AffectationContext* ifccParser::StatementContext::affectation() {
  return getRuleContext<ifccParser::AffectationContext>(0);
}


size_t ifccParser::StatementContext::getRuleIndex() const {
  return ifccParser::RuleStatement;
}

void ifccParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ifccParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any ifccParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::StatementContext* ifccParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(32);
        declaration();
        break;
      }

      case ifccParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(33);
        affectation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

ifccParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::DeclarationContext::TYPE() {
  return getToken(ifccParser::TYPE, 0);
}

std::vector<ifccParser::InitContext *> ifccParser::DeclarationContext::init() {
  return getRuleContexts<ifccParser::InitContext>();
}

ifccParser::InitContext* ifccParser::DeclarationContext::init(size_t i) {
  return getRuleContext<ifccParser::InitContext>(i);
}

std::vector<tree::TerminalNode *> ifccParser::DeclarationContext::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::DeclarationContext::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}


size_t ifccParser::DeclarationContext::getRuleIndex() const {
  return ifccParser::RuleDeclaration;
}

void ifccParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void ifccParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


std::any ifccParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::DeclarationContext* ifccParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(ifccParser::TYPE);
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(37);
      init();
      break;
    }

    case 2: {
      setState(38);
      match(ifccParser::VAR);
      break;
    }

    default:
      break;
    }
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__6) {
      setState(41);
      match(ifccParser::T__6);
      setState(44);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(42);
        init();
        break;
      }

      case 2: {
        setState(43);
        match(ifccParser::VAR);
        break;
      }

      default:
        break;
      }
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51);
    match(ifccParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitContext ------------------------------------------------------------------

ifccParser::InitContext::InitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::InitContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExpressionContext* ifccParser::InitContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::InitContext::getRuleIndex() const {
  return ifccParser::RuleInit;
}

void ifccParser::InitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInit(this);
}

void ifccParser::InitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInit(this);
}


std::any ifccParser::InitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitInit(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::InitContext* ifccParser::init() {
  InitContext *_localctx = _tracker.createInstance<InitContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(ifccParser::VAR);
    setState(54);
    match(ifccParser::T__7);
    setState(55);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AffectationContext ------------------------------------------------------------------

ifccParser::AffectationContext::AffectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::AffectationContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExpressionContext* ifccParser::AffectationContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::AffectationContext::getRuleIndex() const {
  return ifccParser::RuleAffectation;
}

void ifccParser::AffectationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAffectation(this);
}

void ifccParser::AffectationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAffectation(this);
}


std::any ifccParser::AffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AffectationContext* ifccParser::affectation() {
  AffectationContext *_localctx = _tracker.createInstance<AffectationContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleAffectation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(ifccParser::VAR);
    setState(58);
    match(ifccParser::T__7);
    setState(59);
    expression();
    setState(60);
    match(ifccParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ifccParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ExpressionContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::ExpressionContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ExpressionContext* ifccParser::ExpressionContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::ExpressionContext::getRuleIndex() const {
  return ifccParser::RuleExpression;
}

void ifccParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ifccParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any ifccParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpressionContext* ifccParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(62);
      match(ifccParser::VAR);
      break;
    }

    case 2: {
      setState(63);
      match(ifccParser::CONST);
      break;
    }

    case 3: {
      setState(64);
      match(ifccParser::VAR);
      setState(65);
      match(ifccParser::T__7);
      setState(66);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void ifccParser::initialize() {
  std::call_once(ifccParserOnceFlag, ifccParserInitialize);
}
