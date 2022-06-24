
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
      "axiom", "prog", "function", "functionDeclaration", "parameters", 
      "parameter", "arguments", "argument", "block", "statement", "statementWithoutDeclaration", 
      "empty", "ifBlock", "elseBlock", "whileBlock", "ret", "declaration", 
      "rawDeclaration", "expAssignment", "assignment", "expression"
    },
    std::vector<std::string>{
      "", "'void'", "'('", "')'", "','", "'{'", "'}'", "'='", "'-'", "'!'", 
      "'+'", "'~'", "'*'", "'/'", "'%'", "'<<'", "'>>'", "'<'", "'<='", 
      "'>='", "'>'", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", 
      "';'", "'if'", "'else'", "'while'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "SEMICOLON", "IF", "ELSE", 
      "WHILE", "RETURN", "TYPE", "COMMENT", "CONST", "VAR", "DIRECTIVE", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,38,234,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,1,
  	0,1,0,1,1,1,1,5,1,48,8,1,10,1,12,1,51,9,1,1,2,1,2,1,2,1,2,3,2,57,8,2,
  	1,2,1,2,1,2,1,3,1,3,1,3,1,3,3,3,66,8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,74,
  	8,4,10,4,12,4,77,9,4,1,5,1,5,1,5,1,6,1,6,1,6,5,6,85,8,6,10,6,12,6,88,
  	9,6,1,7,1,7,1,8,1,8,5,8,94,8,8,10,8,12,8,97,9,8,1,8,1,8,1,9,1,9,3,9,103,
  	8,9,1,10,1,10,1,10,1,10,1,10,1,10,3,10,111,8,10,1,11,3,11,114,8,11,1,
  	11,1,11,1,12,1,12,1,12,1,12,3,12,122,8,12,1,12,1,12,1,12,3,12,127,8,12,
  	1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,3,15,141,
  	8,15,1,15,1,15,1,16,1,16,1,16,1,16,5,16,149,8,16,10,16,12,16,152,9,16,
  	1,16,1,16,1,17,1,17,1,17,1,17,5,17,160,8,17,10,17,12,17,163,9,17,1,17,
  	3,17,166,8,17,1,18,1,18,4,18,170,8,18,11,18,12,18,171,1,18,1,18,1,19,
  	1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,185,8,20,1,20,1,20,1,20,
  	1,20,1,20,3,20,192,8,20,1,20,1,20,1,20,3,20,197,8,20,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,229,
  	8,20,10,20,12,20,232,9,20,1,20,0,1,40,21,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,30,32,34,36,38,40,0,7,2,0,1,1,33,33,1,0,8,11,1,0,12,14,2,
  	0,8,8,10,10,1,0,15,16,1,0,17,20,1,0,21,22,249,0,42,1,0,0,0,2,49,1,0,0,
  	0,4,52,1,0,0,0,6,61,1,0,0,0,8,70,1,0,0,0,10,78,1,0,0,0,12,81,1,0,0,0,
  	14,89,1,0,0,0,16,91,1,0,0,0,18,102,1,0,0,0,20,110,1,0,0,0,22,113,1,0,
  	0,0,24,117,1,0,0,0,26,128,1,0,0,0,28,131,1,0,0,0,30,137,1,0,0,0,32,144,
  	1,0,0,0,34,155,1,0,0,0,36,169,1,0,0,0,38,175,1,0,0,0,40,196,1,0,0,0,42,
  	43,3,2,1,0,43,44,5,0,0,1,44,1,1,0,0,0,45,48,3,4,2,0,46,48,3,6,3,0,47,
  	45,1,0,0,0,47,46,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,
  	3,1,0,0,0,51,49,1,0,0,0,52,53,7,0,0,0,53,54,5,36,0,0,54,56,5,2,0,0,55,
  	57,3,8,4,0,56,55,1,0,0,0,56,57,1,0,0,0,57,58,1,0,0,0,58,59,5,3,0,0,59,
  	60,3,16,8,0,60,5,1,0,0,0,61,62,7,0,0,0,62,63,5,36,0,0,63,65,5,2,0,0,64,
  	66,3,8,4,0,65,64,1,0,0,0,65,66,1,0,0,0,66,67,1,0,0,0,67,68,5,3,0,0,68,
  	69,5,28,0,0,69,7,1,0,0,0,70,75,3,10,5,0,71,72,5,4,0,0,72,74,3,10,5,0,
  	73,71,1,0,0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,76,9,1,0,0,0,
  	77,75,1,0,0,0,78,79,5,33,0,0,79,80,5,36,0,0,80,11,1,0,0,0,81,86,3,14,
  	7,0,82,83,5,4,0,0,83,85,3,14,7,0,84,82,1,0,0,0,85,88,1,0,0,0,86,84,1,
  	0,0,0,86,87,1,0,0,0,87,13,1,0,0,0,88,86,1,0,0,0,89,90,3,40,20,0,90,15,
  	1,0,0,0,91,95,5,5,0,0,92,94,3,18,9,0,93,92,1,0,0,0,94,97,1,0,0,0,95,93,
  	1,0,0,0,95,96,1,0,0,0,96,98,1,0,0,0,97,95,1,0,0,0,98,99,5,6,0,0,99,17,
  	1,0,0,0,100,103,3,20,10,0,101,103,3,32,16,0,102,100,1,0,0,0,102,101,1,
  	0,0,0,103,19,1,0,0,0,104,111,3,22,11,0,105,111,3,38,19,0,106,111,3,30,
  	15,0,107,111,3,24,12,0,108,111,3,28,14,0,109,111,3,16,8,0,110,104,1,0,
  	0,0,110,105,1,0,0,0,110,106,1,0,0,0,110,107,1,0,0,0,110,108,1,0,0,0,110,
  	109,1,0,0,0,111,21,1,0,0,0,112,114,3,40,20,0,113,112,1,0,0,0,113,114,
  	1,0,0,0,114,115,1,0,0,0,115,116,5,28,0,0,116,23,1,0,0,0,117,118,5,29,
  	0,0,118,121,5,2,0,0,119,122,3,40,20,0,120,122,3,36,18,0,121,119,1,0,0,
  	0,121,120,1,0,0,0,122,123,1,0,0,0,123,124,5,3,0,0,124,126,3,20,10,0,125,
  	127,3,26,13,0,126,125,1,0,0,0,126,127,1,0,0,0,127,25,1,0,0,0,128,129,
  	5,30,0,0,129,130,3,18,9,0,130,27,1,0,0,0,131,132,5,31,0,0,132,133,5,2,
  	0,0,133,134,3,40,20,0,134,135,5,3,0,0,135,136,3,20,10,0,136,29,1,0,0,
  	0,137,140,5,32,0,0,138,141,3,40,20,0,139,141,3,36,18,0,140,138,1,0,0,
  	0,140,139,1,0,0,0,141,142,1,0,0,0,142,143,5,28,0,0,143,31,1,0,0,0,144,
  	145,5,33,0,0,145,150,3,34,17,0,146,147,5,4,0,0,147,149,3,34,17,0,148,
  	146,1,0,0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,153,1,
  	0,0,0,152,150,1,0,0,0,153,154,5,28,0,0,154,33,1,0,0,0,155,165,5,36,0,
  	0,156,161,5,7,0,0,157,158,5,36,0,0,158,160,5,7,0,0,159,157,1,0,0,0,160,
  	163,1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,164,1,0,0,0,163,161,1,
  	0,0,0,164,166,3,40,20,0,165,156,1,0,0,0,165,166,1,0,0,0,166,35,1,0,0,
  	0,167,168,5,36,0,0,168,170,5,7,0,0,169,167,1,0,0,0,170,171,1,0,0,0,171,
  	169,1,0,0,0,171,172,1,0,0,0,172,173,1,0,0,0,173,174,3,40,20,0,174,37,
  	1,0,0,0,175,176,3,36,18,0,176,177,5,28,0,0,177,39,1,0,0,0,178,179,6,20,
  	-1,0,179,197,5,36,0,0,180,197,5,35,0,0,181,184,5,2,0,0,182,185,3,40,20,
  	0,183,185,3,36,18,0,184,182,1,0,0,0,184,183,1,0,0,0,185,186,1,0,0,0,186,
  	187,5,3,0,0,187,197,1,0,0,0,188,189,5,36,0,0,189,191,5,2,0,0,190,192,
  	3,12,6,0,191,190,1,0,0,0,191,192,1,0,0,0,192,193,1,0,0,0,193,197,5,3,
  	0,0,194,195,7,1,0,0,195,197,3,40,20,11,196,178,1,0,0,0,196,180,1,0,0,
  	0,196,181,1,0,0,0,196,188,1,0,0,0,196,194,1,0,0,0,197,230,1,0,0,0,198,
  	199,10,10,0,0,199,200,7,2,0,0,200,229,3,40,20,11,201,202,10,9,0,0,202,
  	203,7,3,0,0,203,229,3,40,20,10,204,205,10,8,0,0,205,206,7,4,0,0,206,229,
  	3,40,20,9,207,208,10,7,0,0,208,209,7,5,0,0,209,229,3,40,20,8,210,211,
  	10,6,0,0,211,212,7,6,0,0,212,229,3,40,20,7,213,214,10,5,0,0,214,215,5,
  	23,0,0,215,229,3,40,20,6,216,217,10,4,0,0,217,218,5,24,0,0,218,229,3,
  	40,20,5,219,220,10,3,0,0,220,221,5,25,0,0,221,229,3,40,20,4,222,223,10,
  	2,0,0,223,224,5,26,0,0,224,229,3,40,20,3,225,226,10,1,0,0,226,227,5,27,
  	0,0,227,229,3,40,20,2,228,198,1,0,0,0,228,201,1,0,0,0,228,204,1,0,0,0,
  	228,207,1,0,0,0,228,210,1,0,0,0,228,213,1,0,0,0,228,216,1,0,0,0,228,219,
  	1,0,0,0,228,222,1,0,0,0,228,225,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,
  	0,230,231,1,0,0,0,231,41,1,0,0,0,232,230,1,0,0,0,22,47,49,56,65,75,86,
  	95,102,110,113,121,126,140,150,161,165,171,184,191,196,228,230
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
    setState(42);
    prog();
    setState(43);
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

std::vector<ifccParser::FunctionDeclarationContext *> ifccParser::ProgContext::functionDeclaration() {
  return getRuleContexts<ifccParser::FunctionDeclarationContext>();
}

ifccParser::FunctionDeclarationContext* ifccParser::ProgContext::functionDeclaration(size_t i) {
  return getRuleContext<ifccParser::FunctionDeclarationContext>(i);
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
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__0

    || _la == ifccParser::TYPE) {
      setState(47);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(45);
        function();
        break;
      }

      case 2: {
        setState(46);
        functionDeclaration();
        break;
      }

      default:
        break;
      }
      setState(51);
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
    setState(52);
    _la = _input->LA(1);
    if (!(_la == ifccParser::T__0

    || _la == ifccParser::TYPE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(53);
    match(ifccParser::VAR);
    setState(54);
    match(ifccParser::T__1);
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::TYPE) {
      setState(55);
      parameters();
    }
    setState(58);
    match(ifccParser::T__2);
    setState(59);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

ifccParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::FunctionDeclarationContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::FunctionDeclarationContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
}

tree::TerminalNode* ifccParser::FunctionDeclarationContext::TYPE() {
  return getToken(ifccParser::TYPE, 0);
}

ifccParser::ParametersContext* ifccParser::FunctionDeclarationContext::parameters() {
  return getRuleContext<ifccParser::ParametersContext>(0);
}


size_t ifccParser::FunctionDeclarationContext::getRuleIndex() const {
  return ifccParser::RuleFunctionDeclaration;
}

void ifccParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void ifccParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}


std::any ifccParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::FunctionDeclarationContext* ifccParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleFunctionDeclaration);
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
    setState(61);
    _la = _input->LA(1);
    if (!(_la == ifccParser::T__0

    || _la == ifccParser::TYPE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(62);
    match(ifccParser::VAR);
    setState(63);
    match(ifccParser::T__1);
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::TYPE) {
      setState(64);
      parameters();
    }
    setState(67);
    match(ifccParser::T__2);
    setState(68);
    match(ifccParser::SEMICOLON);
   
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
  enterRule(_localctx, 8, ifccParser::RuleParameters);
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
    setState(70);
    parameter();
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__3) {
      setState(71);
      match(ifccParser::T__3);
      setState(72);
      parameter();
      setState(77);
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
  enterRule(_localctx, 10, ifccParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(ifccParser::TYPE);
    setState(79);
    match(ifccParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

ifccParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::ArgumentContext *> ifccParser::ArgumentsContext::argument() {
  return getRuleContexts<ifccParser::ArgumentContext>();
}

ifccParser::ArgumentContext* ifccParser::ArgumentsContext::argument(size_t i) {
  return getRuleContext<ifccParser::ArgumentContext>(i);
}


size_t ifccParser::ArgumentsContext::getRuleIndex() const {
  return ifccParser::RuleArguments;
}

void ifccParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void ifccParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any ifccParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ArgumentsContext* ifccParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleArguments);
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
    setState(81);
    argument();
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__3) {
      setState(82);
      match(ifccParser::T__3);
      setState(83);
      argument();
      setState(88);
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

//----------------- ArgumentContext ------------------------------------------------------------------

ifccParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ExpressionContext* ifccParser::ArgumentContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::ArgumentContext::getRuleIndex() const {
  return ifccParser::RuleArgument;
}

void ifccParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void ifccParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}


std::any ifccParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ArgumentContext* ifccParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    expression(0);
   
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
  enterRule(_localctx, 16, ifccParser::RuleBlock);
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
    setState(91);
    match(ifccParser::T__4);
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__1)
      | (1ULL << ifccParser::T__4)
      | (1ULL << ifccParser::T__7)
      | (1ULL << ifccParser::T__8)
      | (1ULL << ifccParser::T__9)
      | (1ULL << ifccParser::T__10)
      | (1ULL << ifccParser::SEMICOLON)
      | (1ULL << ifccParser::IF)
      | (1ULL << ifccParser::WHILE)
      | (1ULL << ifccParser::RETURN)
      | (1ULL << ifccParser::TYPE)
      | (1ULL << ifccParser::CONST)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(92);
      statement();
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
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

ifccParser::StatementWithoutDeclarationContext* ifccParser::StatementContext::statementWithoutDeclaration() {
  return getRuleContext<ifccParser::StatementWithoutDeclarationContext>(0);
}

ifccParser::DeclarationContext* ifccParser::StatementContext::declaration() {
  return getRuleContext<ifccParser::DeclarationContext>(0);
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
  enterRule(_localctx, 18, ifccParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__1:
      case ifccParser::T__4:
      case ifccParser::T__7:
      case ifccParser::T__8:
      case ifccParser::T__9:
      case ifccParser::T__10:
      case ifccParser::SEMICOLON:
      case ifccParser::IF:
      case ifccParser::WHILE:
      case ifccParser::RETURN:
      case ifccParser::CONST:
      case ifccParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(100);
        statementWithoutDeclaration();
        break;
      }

      case ifccParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(101);
        declaration();
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

//----------------- StatementWithoutDeclarationContext ------------------------------------------------------------------

ifccParser::StatementWithoutDeclarationContext::StatementWithoutDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::EmptyContext* ifccParser::StatementWithoutDeclarationContext::empty() {
  return getRuleContext<ifccParser::EmptyContext>(0);
}

ifccParser::AssignmentContext* ifccParser::StatementWithoutDeclarationContext::assignment() {
  return getRuleContext<ifccParser::AssignmentContext>(0);
}

ifccParser::RetContext* ifccParser::StatementWithoutDeclarationContext::ret() {
  return getRuleContext<ifccParser::RetContext>(0);
}

ifccParser::IfBlockContext* ifccParser::StatementWithoutDeclarationContext::ifBlock() {
  return getRuleContext<ifccParser::IfBlockContext>(0);
}

ifccParser::WhileBlockContext* ifccParser::StatementWithoutDeclarationContext::whileBlock() {
  return getRuleContext<ifccParser::WhileBlockContext>(0);
}

ifccParser::BlockContext* ifccParser::StatementWithoutDeclarationContext::block() {
  return getRuleContext<ifccParser::BlockContext>(0);
}


size_t ifccParser::StatementWithoutDeclarationContext::getRuleIndex() const {
  return ifccParser::RuleStatementWithoutDeclaration;
}

void ifccParser::StatementWithoutDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementWithoutDeclaration(this);
}

void ifccParser::StatementWithoutDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementWithoutDeclaration(this);
}


std::any ifccParser::StatementWithoutDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatementWithoutDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::StatementWithoutDeclarationContext* ifccParser::statementWithoutDeclaration() {
  StatementWithoutDeclarationContext *_localctx = _tracker.createInstance<StatementWithoutDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 20, ifccParser::RuleStatementWithoutDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(104);
      empty();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(106);
      ret();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(107);
      ifBlock();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(108);
      whileBlock();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(109);
      block();
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

//----------------- EmptyContext ------------------------------------------------------------------

ifccParser::EmptyContext::EmptyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::EmptyContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
}

ifccParser::ExpressionContext* ifccParser::EmptyContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::EmptyContext::getRuleIndex() const {
  return ifccParser::RuleEmpty;
}

void ifccParser::EmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty(this);
}

void ifccParser::EmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty(this);
}


std::any ifccParser::EmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitEmpty(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::EmptyContext* ifccParser::empty() {
  EmptyContext *_localctx = _tracker.createInstance<EmptyContext>(_ctx, getState());
  enterRule(_localctx, 22, ifccParser::RuleEmpty);
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
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__1)
      | (1ULL << ifccParser::T__7)
      | (1ULL << ifccParser::T__8)
      | (1ULL << ifccParser::T__9)
      | (1ULL << ifccParser::T__10)
      | (1ULL << ifccParser::CONST)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(112);
      expression(0);
    }
    setState(115);
    match(ifccParser::SEMICOLON);
   
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

ifccParser::StatementWithoutDeclarationContext* ifccParser::IfBlockContext::statementWithoutDeclaration() {
  return getRuleContext<ifccParser::StatementWithoutDeclarationContext>(0);
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
  enterRule(_localctx, 24, ifccParser::RuleIfBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(ifccParser::IF);
    setState(118);
    match(ifccParser::T__1);
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(119);
      expression(0);
      break;
    }

    case 2: {
      setState(120);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(123);
    match(ifccParser::T__2);
    setState(124);
    statementWithoutDeclaration();
    setState(126);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(125);
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
  enterRule(_localctx, 26, ifccParser::RuleElseBlock);

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
    match(ifccParser::ELSE);
    setState(129);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileBlockContext ------------------------------------------------------------------

ifccParser::WhileBlockContext::WhileBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::WhileBlockContext::WHILE() {
  return getToken(ifccParser::WHILE, 0);
}

ifccParser::ExpressionContext* ifccParser::WhileBlockContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::StatementWithoutDeclarationContext* ifccParser::WhileBlockContext::statementWithoutDeclaration() {
  return getRuleContext<ifccParser::StatementWithoutDeclarationContext>(0);
}


size_t ifccParser::WhileBlockContext::getRuleIndex() const {
  return ifccParser::RuleWhileBlock;
}

void ifccParser::WhileBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileBlock(this);
}

void ifccParser::WhileBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileBlock(this);
}


std::any ifccParser::WhileBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitWhileBlock(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::WhileBlockContext* ifccParser::whileBlock() {
  WhileBlockContext *_localctx = _tracker.createInstance<WhileBlockContext>(_ctx, getState());
  enterRule(_localctx, 28, ifccParser::RuleWhileBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(ifccParser::WHILE);
    setState(132);
    match(ifccParser::T__1);
    setState(133);
    expression(0);
    setState(134);
    match(ifccParser::T__2);
    setState(135);
    statementWithoutDeclaration();
   
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

tree::TerminalNode* ifccParser::RetContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
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
  enterRule(_localctx, 30, ifccParser::RuleRet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(ifccParser::RETURN);
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(138);
      expression(0);
      break;
    }

    case 2: {
      setState(139);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(142);
    match(ifccParser::SEMICOLON);
   
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

tree::TerminalNode* ifccParser::DeclarationContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
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
  enterRule(_localctx, 32, ifccParser::RuleDeclaration);
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
    setState(144);
    match(ifccParser::TYPE);
    setState(145);
    rawDeclaration();
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__3) {
      setState(146);
      match(ifccParser::T__3);
      setState(147);
      rawDeclaration();
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(153);
    match(ifccParser::SEMICOLON);
   
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
  enterRule(_localctx, 34, ifccParser::RuleRawDeclaration);
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
    setState(155);
    match(ifccParser::VAR);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__6) {
      setState(156);
      match(ifccParser::T__6);
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(157);
          match(ifccParser::VAR);
          setState(158);
          match(ifccParser::T__6); 
        }
        setState(163);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      setState(164);
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
  enterRule(_localctx, 36, ifccParser::RuleExpAssignment);

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
    setState(169); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(167);
              match(ifccParser::VAR);
              setState(168);
              match(ifccParser::T__6);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(171); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(173);
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

tree::TerminalNode* ifccParser::AssignmentContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
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
  enterRule(_localctx, 38, ifccParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    expAssignment();
    setState(176);
    match(ifccParser::SEMICOLON);
   
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
//----------------- FunctionCallContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::FunctionCallContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ArgumentsContext* ifccParser::FunctionCallContext::arguments() {
  return getRuleContext<ifccParser::ArgumentsContext>(0);
}

ifccParser::FunctionCallContext::FunctionCallContext(ExpressionContext *ctx) { copyFrom(ctx); }

void ifccParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void ifccParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

std::any ifccParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, ifccParser::RuleExpression, precedence);

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
    setState(196);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(179);
      match(ifccParser::VAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(180);
      match(ifccParser::CONST);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      match(ifccParser::T__1);
      setState(184);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(182);
        expression(0);
        break;
      }

      case 2: {
        setState(183);
        expAssignment();
        break;
      }

      default:
        break;
      }
      setState(186);
      match(ifccParser::T__2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(188);
      match(ifccParser::VAR);
      setState(189);
      match(ifccParser::T__1);
      setState(191);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ifccParser::T__1)
        | (1ULL << ifccParser::T__7)
        | (1ULL << ifccParser::T__8)
        | (1ULL << ifccParser::T__9)
        | (1ULL << ifccParser::T__10)
        | (1ULL << ifccParser::CONST)
        | (1ULL << ifccParser::VAR))) != 0)) {
        setState(190);
        arguments();
      }
      setState(193);
      match(ifccParser::T__2);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(194);
      antlrcpp::downCast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ifccParser::T__7)
        | (1ULL << ifccParser::T__8)
        | (1ULL << ifccParser::T__9)
        | (1ULL << ifccParser::T__10))) != 0))) {
        antlrcpp::downCast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(195);
      expression(11);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(228);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<TimesDivModuloContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(198);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(199);
          antlrcpp::downCast<TimesDivModuloContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__11)
            | (1ULL << ifccParser::T__12)
            | (1ULL << ifccParser::T__13))) != 0))) {
            antlrcpp::downCast<TimesDivModuloContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(200);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(201);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(202);
          antlrcpp::downCast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__7

          || _la == ifccParser::T__9)) {
            antlrcpp::downCast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(203);
          expression(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(204);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(205);
          antlrcpp::downCast<ShiftContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__14

          || _la == ifccParser::T__15)) {
            antlrcpp::downCast<ShiftContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(206);
          expression(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(207);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(208);
          antlrcpp::downCast<CompareContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__16)
            | (1ULL << ifccParser::T__17)
            | (1ULL << ifccParser::T__18)
            | (1ULL << ifccParser::T__19))) != 0))) {
            antlrcpp::downCast<CompareContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(209);
          expression(8);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(210);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(211);
          antlrcpp::downCast<EqualContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__20

          || _la == ifccParser::T__21)) {
            antlrcpp::downCast<EqualContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(212);
          expression(7);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitwiseAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(213);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(214);
          antlrcpp::downCast<BitwiseAndContext *>(_localctx)->op = match(ifccParser::T__22);
          setState(215);
          expression(6);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseXorContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(216);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(217);
          antlrcpp::downCast<BitwiseXorContext *>(_localctx)->op = match(ifccParser::T__23);
          setState(218);
          expression(5);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(219);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(220);
          antlrcpp::downCast<BitwiseOrContext *>(_localctx)->op = match(ifccParser::T__24);
          setState(221);
          expression(4);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicalAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(222);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(223);
          antlrcpp::downCast<LogicalAndContext *>(_localctx)->op = match(ifccParser::T__25);
          setState(224);
          expression(3);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(225);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(226);
          antlrcpp::downCast<LogicalOrContext *>(_localctx)->op = match(ifccParser::T__26);
          setState(227);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
    case 20: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
