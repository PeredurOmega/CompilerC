
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
      "axiom", "prog", "function", "parameters", "parameter", "block", "statement", 
      "ifBlock", "elseBlock", "ret", "declaration", "rawDeclaration", "expAssignment", 
      "assignment", "expression"
    },
    std::vector<std::string>{
      "", "'void'", "'('", "')'", "','", "'{'", "'}'", "';'", "'='", "'-'", 
      "'!'", "'+'", "'~'", "'*'", "'/'", "'%'", "'<<'", "'>>'", "'<'", "'<='", 
      "'>='", "'>'", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", 
      "'if'", "'else'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "IF", "ELSE", "RETURN", 
      "TYPE", "COMMENT", "CONST", "VAR", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,37,181,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,1,0,1,1,5,1,35,8,1,10,1,12,1,38,9,1,1,2,1,2,1,2,1,2,3,2,44,
  	8,2,1,2,1,2,1,2,1,3,1,3,1,3,5,3,52,8,3,10,3,12,3,55,9,3,1,4,1,4,1,4,1,
  	5,1,5,5,5,62,8,5,10,5,12,5,65,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,
  	75,8,6,1,7,1,7,1,7,1,7,3,7,81,8,7,1,7,1,7,1,7,3,7,86,8,7,1,8,1,8,1,8,
  	1,9,1,9,1,9,3,9,94,8,9,1,9,1,9,1,10,1,10,1,10,1,10,5,10,102,8,10,10,10,
  	12,10,105,9,10,1,10,1,10,1,11,1,11,1,11,1,11,5,11,113,8,11,10,11,12,11,
  	116,9,11,1,11,3,11,119,8,11,1,12,1,12,4,12,123,8,12,11,12,12,12,124,1,
  	12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,3,14,138,8,14,1,
  	14,1,14,1,14,1,14,3,14,144,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,176,8,14,10,14,12,14,
  	179,9,14,1,14,0,1,28,15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,7,2,
  	0,1,1,32,32,1,0,9,12,1,0,13,15,2,0,9,9,11,11,1,0,16,17,1,0,18,21,1,0,
  	22,23,195,0,30,1,0,0,0,2,36,1,0,0,0,4,39,1,0,0,0,6,48,1,0,0,0,8,56,1,
  	0,0,0,10,59,1,0,0,0,12,74,1,0,0,0,14,76,1,0,0,0,16,87,1,0,0,0,18,90,1,
  	0,0,0,20,97,1,0,0,0,22,108,1,0,0,0,24,122,1,0,0,0,26,128,1,0,0,0,28,143,
  	1,0,0,0,30,31,3,2,1,0,31,32,5,0,0,1,32,1,1,0,0,0,33,35,3,4,2,0,34,33,
  	1,0,0,0,35,38,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,3,1,0,0,0,38,36,
  	1,0,0,0,39,40,7,0,0,0,40,41,5,35,0,0,41,43,5,2,0,0,42,44,3,6,3,0,43,42,
  	1,0,0,0,43,44,1,0,0,0,44,45,1,0,0,0,45,46,5,3,0,0,46,47,3,10,5,0,47,5,
  	1,0,0,0,48,53,3,8,4,0,49,50,5,4,0,0,50,52,3,8,4,0,51,49,1,0,0,0,52,55,
  	1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,7,1,0,0,0,55,53,1,0,0,0,56,57,
  	5,32,0,0,57,58,5,35,0,0,58,9,1,0,0,0,59,63,5,5,0,0,60,62,3,12,6,0,61,
  	60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,66,1,0,0,0,65,
  	63,1,0,0,0,66,67,5,6,0,0,67,11,1,0,0,0,68,75,5,7,0,0,69,75,3,20,10,0,
  	70,75,3,26,13,0,71,75,3,18,9,0,72,75,3,14,7,0,73,75,3,10,5,0,74,68,1,
  	0,0,0,74,69,1,0,0,0,74,70,1,0,0,0,74,71,1,0,0,0,74,72,1,0,0,0,74,73,1,
  	0,0,0,75,13,1,0,0,0,76,77,5,29,0,0,77,80,5,2,0,0,78,81,3,28,14,0,79,81,
  	3,24,12,0,80,78,1,0,0,0,80,79,1,0,0,0,81,82,1,0,0,0,82,83,5,3,0,0,83,
  	85,3,12,6,0,84,86,3,16,8,0,85,84,1,0,0,0,85,86,1,0,0,0,86,15,1,0,0,0,
  	87,88,5,30,0,0,88,89,3,12,6,0,89,17,1,0,0,0,90,93,5,31,0,0,91,94,3,28,
  	14,0,92,94,3,24,12,0,93,91,1,0,0,0,93,92,1,0,0,0,94,95,1,0,0,0,95,96,
  	5,7,0,0,96,19,1,0,0,0,97,98,5,32,0,0,98,103,3,22,11,0,99,100,5,4,0,0,
  	100,102,3,22,11,0,101,99,1,0,0,0,102,105,1,0,0,0,103,101,1,0,0,0,103,
  	104,1,0,0,0,104,106,1,0,0,0,105,103,1,0,0,0,106,107,5,7,0,0,107,21,1,
  	0,0,0,108,118,5,35,0,0,109,114,5,8,0,0,110,111,5,35,0,0,111,113,5,8,0,
  	0,112,110,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,
  	117,1,0,0,0,116,114,1,0,0,0,117,119,3,28,14,0,118,109,1,0,0,0,118,119,
  	1,0,0,0,119,23,1,0,0,0,120,121,5,35,0,0,121,123,5,8,0,0,122,120,1,0,0,
  	0,123,124,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,126,
  	127,3,28,14,0,127,25,1,0,0,0,128,129,3,24,12,0,129,130,5,7,0,0,130,27,
  	1,0,0,0,131,132,6,14,-1,0,132,144,5,35,0,0,133,144,5,34,0,0,134,137,5,
  	2,0,0,135,138,3,28,14,0,136,138,3,24,12,0,137,135,1,0,0,0,137,136,1,0,
  	0,0,138,139,1,0,0,0,139,140,5,3,0,0,140,144,1,0,0,0,141,142,7,1,0,0,142,
  	144,3,28,14,11,143,131,1,0,0,0,143,133,1,0,0,0,143,134,1,0,0,0,143,141,
  	1,0,0,0,144,177,1,0,0,0,145,146,10,10,0,0,146,147,7,2,0,0,147,176,3,28,
  	14,11,148,149,10,9,0,0,149,150,7,3,0,0,150,176,3,28,14,10,151,152,10,
  	8,0,0,152,153,7,4,0,0,153,176,3,28,14,9,154,155,10,7,0,0,155,156,7,5,
  	0,0,156,176,3,28,14,8,157,158,10,6,0,0,158,159,7,6,0,0,159,176,3,28,14,
  	7,160,161,10,5,0,0,161,162,5,24,0,0,162,176,3,28,14,6,163,164,10,4,0,
  	0,164,165,5,25,0,0,165,176,3,28,14,5,166,167,10,3,0,0,167,168,5,26,0,
  	0,168,176,3,28,14,4,169,170,10,2,0,0,170,171,5,27,0,0,171,176,3,28,14,
  	3,172,173,10,1,0,0,173,174,5,28,0,0,174,176,3,28,14,2,175,145,1,0,0,0,
  	175,148,1,0,0,0,175,151,1,0,0,0,175,154,1,0,0,0,175,157,1,0,0,0,175,160,
  	1,0,0,0,175,163,1,0,0,0,175,166,1,0,0,0,175,169,1,0,0,0,175,172,1,0,0,
  	0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,29,1,0,0,0,179,
  	177,1,0,0,0,16,36,43,53,63,74,80,85,93,103,114,118,124,137,143,175,177
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

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
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
    setState(30);
    prog();
    setState(31);
    match(ifccParser::EOF);
   
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

std::vector<ifccParser::FunctionContext *> ifccParser::ProgContext::function() {
  return getRuleContexts<ifccParser::FunctionContext>();
}

ifccParser::FunctionContext* ifccParser::ProgContext::function(size_t i) {
  return getRuleContext<ifccParser::FunctionContext>(i);
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
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__0

    || _la == ifccParser::TYPE) {
      setState(33);
      function();
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

ifccParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::FunctionContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::BlockContext* ifccParser::FunctionContext::block() {
  return getRuleContext<ifccParser::BlockContext>(0);
}

tree::TerminalNode* ifccParser::FunctionContext::TYPE() {
  return getToken(ifccParser::TYPE, 0);
}

ifccParser::ParametersContext* ifccParser::FunctionContext::parameters() {
  return getRuleContext<ifccParser::ParametersContext>(0);
}


size_t ifccParser::FunctionContext::getRuleIndex() const {
  return ifccParser::RuleFunction;
}

void ifccParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void ifccParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any ifccParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::FunctionContext* ifccParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleFunction);
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
    setState(39);
    _la = _input->LA(1);
    if (!(_la == ifccParser::T__0

    || _la == ifccParser::TYPE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(40);
    match(ifccParser::VAR);
    setState(41);
    match(ifccParser::T__1);
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::TYPE) {
      setState(42);
      parameters();
    }
    setState(45);
    match(ifccParser::T__2);
    setState(46);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

ifccParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::ParameterContext *> ifccParser::ParametersContext::parameter() {
  return getRuleContexts<ifccParser::ParameterContext>();
}

ifccParser::ParameterContext* ifccParser::ParametersContext::parameter(size_t i) {
  return getRuleContext<ifccParser::ParameterContext>(i);
}


size_t ifccParser::ParametersContext::getRuleIndex() const {
  return ifccParser::RuleParameters;
}

void ifccParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void ifccParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}


std::any ifccParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ParametersContext* ifccParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleParameters);
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
    setState(48);
    parameter();
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__3) {
      setState(49);
      match(ifccParser::T__3);
      setState(50);
      parameter();
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

ifccParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ParameterContext::TYPE() {
  return getToken(ifccParser::TYPE, 0);
}

tree::TerminalNode* ifccParser::ParameterContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}


size_t ifccParser::ParameterContext::getRuleIndex() const {
  return ifccParser::RuleParameter;
}

void ifccParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void ifccParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


std::any ifccParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ParameterContext* ifccParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(ifccParser::TYPE);
    setState(57);
    match(ifccParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ifccParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::StatementContext *> ifccParser::BlockContext::statement() {
  return getRuleContexts<ifccParser::StatementContext>();
}

ifccParser::StatementContext* ifccParser::BlockContext::statement(size_t i) {
  return getRuleContext<ifccParser::StatementContext>(i);
}


size_t ifccParser::BlockContext::getRuleIndex() const {
  return ifccParser::RuleBlock;
}

void ifccParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void ifccParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any ifccParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::BlockContext* ifccParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleBlock);
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
    setState(59);
    match(ifccParser::T__4);
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__4)
      | (1ULL << ifccParser::T__6)
      | (1ULL << ifccParser::IF)
      | (1ULL << ifccParser::RETURN)
      | (1ULL << ifccParser::TYPE)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(60);
      statement();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
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

ifccParser::AssignmentContext* ifccParser::StatementContext::assignment() {
  return getRuleContext<ifccParser::AssignmentContext>(0);
}

ifccParser::RetContext* ifccParser::StatementContext::ret() {
  return getRuleContext<ifccParser::RetContext>(0);
}

ifccParser::IfBlockContext* ifccParser::StatementContext::ifBlock() {
  return getRuleContext<ifccParser::IfBlockContext>(0);
}

ifccParser::BlockContext* ifccParser::StatementContext::block() {
  return getRuleContext<ifccParser::BlockContext>(0);
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
  enterRule(_localctx, 12, ifccParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        match(ifccParser::T__6);
        break;
      }

      case ifccParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(69);
        declaration();
        break;
      }

      case ifccParser::VAR: {
        enterOuterAlt(_localctx, 3);
        setState(70);
        assignment();
        break;
      }

      case ifccParser::RETURN: {
        enterOuterAlt(_localctx, 4);
        setState(71);
        ret();
        break;
      }

      case ifccParser::IF: {
        enterOuterAlt(_localctx, 5);
        setState(72);
        ifBlock();
        break;
      }

      case ifccParser::T__4: {
        enterOuterAlt(_localctx, 6);
        setState(73);
        block();
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

//----------------- IfBlockContext ------------------------------------------------------------------

ifccParser::IfBlockContext::IfBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::IfBlockContext::IF() {
  return getToken(ifccParser::IF, 0);
}

ifccParser::StatementContext* ifccParser::IfBlockContext::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}

ifccParser::ExpressionContext* ifccParser::IfBlockContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::ExpAssignmentContext* ifccParser::IfBlockContext::expAssignment() {
  return getRuleContext<ifccParser::ExpAssignmentContext>(0);
}

ifccParser::ElseBlockContext* ifccParser::IfBlockContext::elseBlock() {
  return getRuleContext<ifccParser::ElseBlockContext>(0);
}


size_t ifccParser::IfBlockContext::getRuleIndex() const {
  return ifccParser::RuleIfBlock;
}

void ifccParser::IfBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfBlock(this);
}

void ifccParser::IfBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfBlock(this);
}


std::any ifccParser::IfBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitIfBlock(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::IfBlockContext* ifccParser::ifBlock() {
  IfBlockContext *_localctx = _tracker.createInstance<IfBlockContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleIfBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(ifccParser::IF);
    setState(77);
    match(ifccParser::T__1);
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(78);
      expression(0);
      break;
    }

    case 2: {
      setState(79);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(82);
    match(ifccParser::T__2);
    setState(83);
    statement();
    setState(85);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(84);
      elseBlock();
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

//----------------- ElseBlockContext ------------------------------------------------------------------

ifccParser::ElseBlockContext::ElseBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ElseBlockContext::ELSE() {
  return getToken(ifccParser::ELSE, 0);
}

ifccParser::StatementContext* ifccParser::ElseBlockContext::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}


size_t ifccParser::ElseBlockContext::getRuleIndex() const {
  return ifccParser::RuleElseBlock;
}

void ifccParser::ElseBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseBlock(this);
}

void ifccParser::ElseBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseBlock(this);
}


std::any ifccParser::ElseBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitElseBlock(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ElseBlockContext* ifccParser::elseBlock() {
  ElseBlockContext *_localctx = _tracker.createInstance<ElseBlockContext>(_ctx, getState());
  enterRule(_localctx, 16, ifccParser::RuleElseBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(ifccParser::ELSE);
    setState(88);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

ifccParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::RetContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

ifccParser::ExpressionContext* ifccParser::RetContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::ExpAssignmentContext* ifccParser::RetContext::expAssignment() {
  return getRuleContext<ifccParser::ExpAssignmentContext>(0);
}


size_t ifccParser::RetContext::getRuleIndex() const {
  return ifccParser::RuleRet;
}

void ifccParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}

void ifccParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}


std::any ifccParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::RetContext* ifccParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 18, ifccParser::RuleRet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(ifccParser::RETURN);
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(91);
      expression(0);
      break;
    }

    case 2: {
      setState(92);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(95);
    match(ifccParser::T__6);
   
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

std::vector<ifccParser::RawDeclarationContext *> ifccParser::DeclarationContext::rawDeclaration() {
  return getRuleContexts<ifccParser::RawDeclarationContext>();
}

ifccParser::RawDeclarationContext* ifccParser::DeclarationContext::rawDeclaration(size_t i) {
  return getRuleContext<ifccParser::RawDeclarationContext>(i);
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
  enterRule(_localctx, 20, ifccParser::RuleDeclaration);
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
    setState(97);
    match(ifccParser::TYPE);
    setState(98);
    rawDeclaration();
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__3) {
      setState(99);
      match(ifccParser::T__3);
      setState(100);
      rawDeclaration();
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RawDeclarationContext ------------------------------------------------------------------

ifccParser::RawDeclarationContext::RawDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ifccParser::RawDeclarationContext::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::RawDeclarationContext::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}

ifccParser::ExpressionContext* ifccParser::RawDeclarationContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::RawDeclarationContext::getRuleIndex() const {
  return ifccParser::RuleRawDeclaration;
}

void ifccParser::RawDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRawDeclaration(this);
}

void ifccParser::RawDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRawDeclaration(this);
}


std::any ifccParser::RawDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRawDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::RawDeclarationContext* ifccParser::rawDeclaration() {
  RawDeclarationContext *_localctx = _tracker.createInstance<RawDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, ifccParser::RuleRawDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(ifccParser::VAR);
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__7) {
      setState(109);
      match(ifccParser::T__7);
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(110);
          match(ifccParser::VAR);
          setState(111);
          match(ifccParser::T__7); 
        }
        setState(116);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(117);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpAssignmentContext ------------------------------------------------------------------

ifccParser::ExpAssignmentContext::ExpAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ExpressionContext* ifccParser::ExpAssignmentContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> ifccParser::ExpAssignmentContext::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::ExpAssignmentContext::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}


size_t ifccParser::ExpAssignmentContext::getRuleIndex() const {
  return ifccParser::RuleExpAssignment;
}

void ifccParser::ExpAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpAssignment(this);
}

void ifccParser::ExpAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpAssignment(this);
}


std::any ifccParser::ExpAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExpAssignment(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpAssignmentContext* ifccParser::expAssignment() {
  ExpAssignmentContext *_localctx = _tracker.createInstance<ExpAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 24, ifccParser::RuleExpAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(122); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(120);
              match(ifccParser::VAR);
              setState(121);
              match(ifccParser::T__7);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(124); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(126);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ifccParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ExpAssignmentContext* ifccParser::AssignmentContext::expAssignment() {
  return getRuleContext<ifccParser::ExpAssignmentContext>(0);
}


size_t ifccParser::AssignmentContext::getRuleIndex() const {
  return ifccParser::RuleAssignment;
}

void ifccParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void ifccParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any ifccParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AssignmentContext* ifccParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 26, ifccParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    expAssignment();
    setState(129);
    match(ifccParser::T__6);
   
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


size_t ifccParser::ExpressionContext::getRuleIndex() const {
  return ifccParser::RuleExpression;
}

void ifccParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CompareContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::CompareContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::CompareContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::CompareContext::CompareContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::CompareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompare(this);
}
void ifccParser::CompareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompare(this);
}

std::any ifccParser::CompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCompare(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstantContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ConstantContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ConstantContext::ConstantContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}
void ifccParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

std::any ifccParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShiftContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::ShiftContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::ShiftContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::ShiftContext::ShiftContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::ShiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShift(this);
}
void ifccParser::ShiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShift(this);
}

std::any ifccParser::ShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitShift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseXorContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::BitwiseXorContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::BitwiseXorContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::BitwiseXorContext::BitwiseXorContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::BitwiseXorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseXor(this);
}
void ifccParser::BitwiseXorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseXor(this);
}

std::any ifccParser::BitwiseXorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseXor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::LogicalAndContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::LogicalAndContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::LogicalAndContext::LogicalAndContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::LogicalAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAnd(this);
}
void ifccParser::LogicalAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAnd(this);
}

std::any ifccParser::LogicalAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitLogicalAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::AddSubContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::AddSubContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::AddSubContext::AddSubContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void ifccParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}

std::any ifccParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

ifccParser::ExpressionContext* ifccParser::UnaryContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::UnaryContext::UnaryContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}
void ifccParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}

std::any ifccParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseAndContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::BitwiseAndContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::BitwiseAndContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::BitwiseAndContext::BitwiseAndContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::BitwiseAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseAnd(this);
}
void ifccParser::BitwiseAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseAnd(this);
}

std::any ifccParser::BitwiseAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

ifccParser::ExpressionContext* ifccParser::ParenthesisContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::ExpAssignmentContext* ifccParser::ParenthesisContext::expAssignment() {
  return getRuleContext<ifccParser::ExpAssignmentContext>(0);
}

ifccParser::ParenthesisContext::ParenthesisContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::ParenthesisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesis(this);
}
void ifccParser::ParenthesisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesis(this);
}

std::any ifccParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TimesDivModuloContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::TimesDivModuloContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::TimesDivModuloContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::TimesDivModuloContext::TimesDivModuloContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::TimesDivModuloContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimesDivModulo(this);
}
void ifccParser::TimesDivModuloContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimesDivModulo(this);
}

std::any ifccParser::TimesDivModuloContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitTimesDivModulo(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::EqualContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::EqualContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::EqualContext::EqualContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::EqualContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqual(this);
}
void ifccParser::EqualContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqual(this);
}

std::any ifccParser::EqualContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitEqual(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VariableContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void ifccParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

std::any ifccParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOrContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::BitwiseOrContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::BitwiseOrContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::BitwiseOrContext::BitwiseOrContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::BitwiseOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseOr(this);
}
void ifccParser::BitwiseOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseOr(this);
}

std::any ifccParser::BitwiseOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::LogicalOrContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::LogicalOrContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::LogicalOrContext::LogicalOrContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::LogicalOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOr(this);
}
void ifccParser::LogicalOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOr(this);
}

std::any ifccParser::LogicalOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitLogicalOr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpressionContext* ifccParser::expression() {
   return expression(0);
}

ifccParser::ExpressionContext* ifccParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ifccParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, ifccParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(143);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(132);
        match(ifccParser::VAR);
        break;
      }

      case ifccParser::CONST: {
        _localctx = _tracker.createInstance<ConstantContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(133);
        match(ifccParser::CONST);
        break;
      }

      case ifccParser::T__1: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(134);
        match(ifccParser::T__1);
        setState(137);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(135);
          expression(0);
          break;
        }

        case 2: {
          setState(136);
          expAssignment();
          break;
        }

        default:
          break;
        }
        setState(139);
        match(ifccParser::T__2);
        break;
      }

      case ifccParser::T__8:
      case ifccParser::T__9:
      case ifccParser::T__10:
      case ifccParser::T__11: {
        _localctx = _tracker.createInstance<UnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(141);
        antlrcpp::downCast<UnaryContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ifccParser::T__8)
          | (1ULL << ifccParser::T__9)
          | (1ULL << ifccParser::T__10)
          | (1ULL << ifccParser::T__11))) != 0))) {
          antlrcpp::downCast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(142);
        expression(11);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(175);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<TimesDivModuloContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(145);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(146);
          antlrcpp::downCast<TimesDivModuloContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__12)
            | (1ULL << ifccParser::T__13)
            | (1ULL << ifccParser::T__14))) != 0))) {
            antlrcpp::downCast<TimesDivModuloContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(147);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(148);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(149);
          antlrcpp::downCast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__8

          || _la == ifccParser::T__10)) {
            antlrcpp::downCast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(150);
          expression(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(151);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(152);
          antlrcpp::downCast<ShiftContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__15

          || _la == ifccParser::T__16)) {
            antlrcpp::downCast<ShiftContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(153);
          expression(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(154);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(155);
          antlrcpp::downCast<CompareContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__17)
            | (1ULL << ifccParser::T__18)
            | (1ULL << ifccParser::T__19)
            | (1ULL << ifccParser::T__20))) != 0))) {
            antlrcpp::downCast<CompareContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(156);
          expression(8);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(157);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(158);
          antlrcpp::downCast<EqualContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__21

          || _la == ifccParser::T__22)) {
            antlrcpp::downCast<EqualContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(159);
          expression(7);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitwiseAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(160);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(161);
          antlrcpp::downCast<BitwiseAndContext *>(_localctx)->op = match(ifccParser::T__23);
          setState(162);
          expression(6);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseXorContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(163);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(164);
          antlrcpp::downCast<BitwiseXorContext *>(_localctx)->op = match(ifccParser::T__24);
          setState(165);
          expression(5);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(166);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(167);
          antlrcpp::downCast<BitwiseOrContext *>(_localctx)->op = match(ifccParser::T__25);
          setState(168);
          expression(4);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicalAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(169);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(170);
          antlrcpp::downCast<LogicalAndContext *>(_localctx)->op = match(ifccParser::T__26);
          setState(171);
          expression(3);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(172);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(173);
          antlrcpp::downCast<LogicalOrContext *>(_localctx)->op = match(ifccParser::T__27);
          setState(174);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 14: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);
    case 6: return precpred(_ctx, 4);
    case 7: return precpred(_ctx, 3);
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void ifccParser::initialize() {
  std::call_once(ifccParserOnceFlag, ifccParserInitialize);
}
