
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
      "axiom", "prog", "function", "functionDeclaration", "staticVariable", 
      "parameters", "parameter", "arguments", "argument", "block", "statement", 
      "statementWithoutDeclaration", "procedureCall", "empty", "ifBlock", 
      "elseBlock", "whileBlock", "ret", "declaration", "rawDeclaration", 
      "expAssignment", "assignment", "exp", "expression"
    },
    std::vector<std::string>{
      "", "'void'", "'('", "')'", "'='", "','", "'{'", "'}'", "'-'", "'!'", 
      "'+'", "'~'", "'*'", "'/'", "'%'", "'<<'", "'>>'", "'<'", "'<='", 
      "'>='", "'>'", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", 
      "';'", "'if'", "'else'", "'while'", "'return'", "", "'static'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "SEMICOLON", "IF", "ELSE", 
      "WHILE", "RETURN", "TYPE", "STATIC", "COMMENT", "INT_CONST", "CHAR_CONST", 
      "VAR", "DIRECTIVE", "WS", "CONST"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,264,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,5,1,55,8,1,10,1,12,1,58,
  	9,1,1,2,1,2,1,2,1,2,3,2,64,8,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,3,3,73,8,3,
  	1,3,1,3,1,3,1,4,3,4,79,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,90,
  	8,5,10,5,12,5,93,9,5,1,6,1,6,1,6,1,7,1,7,1,7,5,7,101,8,7,10,7,12,7,104,
  	9,7,1,8,1,8,1,9,1,9,5,9,110,8,9,10,9,12,9,113,9,9,1,9,1,9,1,10,1,10,3,
  	10,119,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,128,8,11,1,12,1,12,
  	1,12,3,12,133,8,12,1,12,1,12,1,12,1,13,3,13,139,8,13,1,13,1,13,1,14,1,
  	14,1,14,1,14,3,14,147,8,14,1,14,1,14,1,14,3,14,152,8,14,1,15,1,15,1,15,
  	1,16,1,16,1,16,1,16,3,16,161,8,16,1,16,1,16,1,16,1,17,1,17,1,17,3,17,
  	169,8,17,1,17,1,17,1,18,1,18,1,18,1,18,5,18,177,8,18,10,18,12,18,180,
  	9,18,1,18,1,18,1,19,1,19,1,19,1,19,5,19,188,8,19,10,19,12,19,191,9,19,
  	1,19,3,19,194,8,19,1,20,1,20,4,20,198,8,20,11,20,12,20,199,1,20,1,20,
  	1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,3,23,215,8,23,
  	1,23,1,23,1,23,1,23,1,23,3,23,222,8,23,1,23,1,23,1,23,3,23,227,8,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,5,23,259,8,23,10,23,12,23,262,9,23,1,23,0,1,46,24,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,8,2,0,1,1,33,
  	33,1,0,36,37,1,0,8,11,1,0,12,14,2,0,8,8,10,10,1,0,15,16,1,0,17,20,1,0,
  	21,22,281,0,48,1,0,0,0,2,56,1,0,0,0,4,59,1,0,0,0,6,68,1,0,0,0,8,78,1,
  	0,0,0,10,86,1,0,0,0,12,94,1,0,0,0,14,97,1,0,0,0,16,105,1,0,0,0,18,107,
  	1,0,0,0,20,118,1,0,0,0,22,127,1,0,0,0,24,129,1,0,0,0,26,138,1,0,0,0,28,
  	142,1,0,0,0,30,153,1,0,0,0,32,156,1,0,0,0,34,165,1,0,0,0,36,172,1,0,0,
  	0,38,183,1,0,0,0,40,197,1,0,0,0,42,203,1,0,0,0,44,206,1,0,0,0,46,226,
  	1,0,0,0,48,49,3,2,1,0,49,50,5,0,0,1,50,1,1,0,0,0,51,55,3,4,2,0,52,55,
  	3,6,3,0,53,55,3,8,4,0,54,51,1,0,0,0,54,52,1,0,0,0,54,53,1,0,0,0,55,58,
  	1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,3,1,0,0,0,58,56,1,0,0,0,59,60,
  	7,0,0,0,60,61,5,38,0,0,61,63,5,2,0,0,62,64,3,10,5,0,63,62,1,0,0,0,63,
  	64,1,0,0,0,64,65,1,0,0,0,65,66,5,3,0,0,66,67,3,18,9,0,67,5,1,0,0,0,68,
  	69,7,0,0,0,69,70,5,38,0,0,70,72,5,2,0,0,71,73,3,10,5,0,72,71,1,0,0,0,
  	72,73,1,0,0,0,73,74,1,0,0,0,74,75,5,3,0,0,75,76,5,28,0,0,76,7,1,0,0,0,
  	77,79,5,34,0,0,78,77,1,0,0,0,78,79,1,0,0,0,79,80,1,0,0,0,80,81,5,33,0,
  	0,81,82,5,38,0,0,82,83,5,4,0,0,83,84,5,41,0,0,84,85,5,28,0,0,85,9,1,0,
  	0,0,86,91,3,12,6,0,87,88,5,5,0,0,88,90,3,12,6,0,89,87,1,0,0,0,90,93,1,
  	0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,11,1,0,0,0,93,91,1,0,0,0,94,95,5,
  	33,0,0,95,96,5,38,0,0,96,13,1,0,0,0,97,102,3,16,8,0,98,99,5,5,0,0,99,
  	101,3,16,8,0,100,98,1,0,0,0,101,104,1,0,0,0,102,100,1,0,0,0,102,103,1,
  	0,0,0,103,15,1,0,0,0,104,102,1,0,0,0,105,106,3,46,23,0,106,17,1,0,0,0,
  	107,111,5,6,0,0,108,110,3,20,10,0,109,108,1,0,0,0,110,113,1,0,0,0,111,
  	109,1,0,0,0,111,112,1,0,0,0,112,114,1,0,0,0,113,111,1,0,0,0,114,115,5,
  	7,0,0,115,19,1,0,0,0,116,119,3,22,11,0,117,119,3,36,18,0,118,116,1,0,
  	0,0,118,117,1,0,0,0,119,21,1,0,0,0,120,128,3,42,21,0,121,128,3,34,17,
  	0,122,128,3,28,14,0,123,128,3,32,16,0,124,128,3,24,12,0,125,128,3,18,
  	9,0,126,128,3,26,13,0,127,120,1,0,0,0,127,121,1,0,0,0,127,122,1,0,0,0,
  	127,123,1,0,0,0,127,124,1,0,0,0,127,125,1,0,0,0,127,126,1,0,0,0,128,23,
  	1,0,0,0,129,130,5,38,0,0,130,132,5,2,0,0,131,133,3,14,7,0,132,131,1,0,
  	0,0,132,133,1,0,0,0,133,134,1,0,0,0,134,135,5,3,0,0,135,136,5,28,0,0,
  	136,25,1,0,0,0,137,139,3,44,22,0,138,137,1,0,0,0,138,139,1,0,0,0,139,
  	140,1,0,0,0,140,141,5,28,0,0,141,27,1,0,0,0,142,143,5,29,0,0,143,146,
  	5,2,0,0,144,147,3,44,22,0,145,147,3,40,20,0,146,144,1,0,0,0,146,145,1,
  	0,0,0,147,148,1,0,0,0,148,149,5,3,0,0,149,151,3,22,11,0,150,152,3,30,
  	15,0,151,150,1,0,0,0,151,152,1,0,0,0,152,29,1,0,0,0,153,154,5,30,0,0,
  	154,155,3,20,10,0,155,31,1,0,0,0,156,157,5,31,0,0,157,160,5,2,0,0,158,
  	161,3,44,22,0,159,161,3,40,20,0,160,158,1,0,0,0,160,159,1,0,0,0,161,162,
  	1,0,0,0,162,163,5,3,0,0,163,164,3,22,11,0,164,33,1,0,0,0,165,168,5,32,
  	0,0,166,169,3,44,22,0,167,169,3,40,20,0,168,166,1,0,0,0,168,167,1,0,0,
  	0,169,170,1,0,0,0,170,171,5,28,0,0,171,35,1,0,0,0,172,173,5,33,0,0,173,
  	178,3,38,19,0,174,175,5,5,0,0,175,177,3,38,19,0,176,174,1,0,0,0,177,180,
  	1,0,0,0,178,176,1,0,0,0,178,179,1,0,0,0,179,181,1,0,0,0,180,178,1,0,0,
  	0,181,182,5,28,0,0,182,37,1,0,0,0,183,193,5,38,0,0,184,189,5,4,0,0,185,
  	186,5,38,0,0,186,188,5,4,0,0,187,185,1,0,0,0,188,191,1,0,0,0,189,187,
  	1,0,0,0,189,190,1,0,0,0,190,192,1,0,0,0,191,189,1,0,0,0,192,194,3,44,
  	22,0,193,184,1,0,0,0,193,194,1,0,0,0,194,39,1,0,0,0,195,196,5,38,0,0,
  	196,198,5,4,0,0,197,195,1,0,0,0,198,199,1,0,0,0,199,197,1,0,0,0,199,200,
  	1,0,0,0,200,201,1,0,0,0,201,202,3,44,22,0,202,41,1,0,0,0,203,204,3,40,
  	20,0,204,205,5,28,0,0,205,43,1,0,0,0,206,207,3,46,23,0,207,45,1,0,0,0,
  	208,209,6,23,-1,0,209,227,5,38,0,0,210,227,7,1,0,0,211,214,5,2,0,0,212,
  	215,3,46,23,0,213,215,3,40,20,0,214,212,1,0,0,0,214,213,1,0,0,0,215,216,
  	1,0,0,0,216,217,5,3,0,0,217,227,1,0,0,0,218,219,5,38,0,0,219,221,5,2,
  	0,0,220,222,3,14,7,0,221,220,1,0,0,0,221,222,1,0,0,0,222,223,1,0,0,0,
  	223,227,5,3,0,0,224,225,7,2,0,0,225,227,3,46,23,11,226,208,1,0,0,0,226,
  	210,1,0,0,0,226,211,1,0,0,0,226,218,1,0,0,0,226,224,1,0,0,0,227,260,1,
  	0,0,0,228,229,10,10,0,0,229,230,7,3,0,0,230,259,3,46,23,11,231,232,10,
  	9,0,0,232,233,7,4,0,0,233,259,3,46,23,10,234,235,10,8,0,0,235,236,7,5,
  	0,0,236,259,3,46,23,9,237,238,10,7,0,0,238,239,7,6,0,0,239,259,3,46,23,
  	8,240,241,10,6,0,0,241,242,7,7,0,0,242,259,3,46,23,7,243,244,10,5,0,0,
  	244,245,5,23,0,0,245,259,3,46,23,6,246,247,10,4,0,0,247,248,5,24,0,0,
  	248,259,3,46,23,5,249,250,10,3,0,0,250,251,5,25,0,0,251,259,3,46,23,4,
  	252,253,10,2,0,0,253,254,5,26,0,0,254,259,3,46,23,3,255,256,10,1,0,0,
  	256,257,5,27,0,0,257,259,3,46,23,2,258,228,1,0,0,0,258,231,1,0,0,0,258,
  	234,1,0,0,0,258,237,1,0,0,0,258,240,1,0,0,0,258,243,1,0,0,0,258,246,1,
  	0,0,0,258,249,1,0,0,0,258,252,1,0,0,0,258,255,1,0,0,0,259,262,1,0,0,0,
  	260,258,1,0,0,0,260,261,1,0,0,0,261,47,1,0,0,0,262,260,1,0,0,0,25,54,
  	56,63,72,78,91,102,111,118,127,132,138,146,151,160,168,178,189,193,199,
  	214,221,226,258,260
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
    setState(48);
    prog();
    setState(49);
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

std::vector<ifccParser::StaticVariableContext *> ifccParser::ProgContext::staticVariable() {
  return getRuleContexts<ifccParser::StaticVariableContext>();
}

ifccParser::StaticVariableContext* ifccParser::ProgContext::staticVariable(size_t i) {
  return getRuleContext<ifccParser::StaticVariableContext>(i);
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
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__0)
      | (1ULL << ifccParser::TYPE)
      | (1ULL << ifccParser::STATIC))) != 0)) {
      setState(54);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(51);
        function();
        break;
      }

      case 2: {
        setState(52);
        functionDeclaration();
        break;
      }

      case 3: {
        setState(53);
        staticVariable();
        break;
      }

      default:
        break;
      }
      setState(58);
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
    setState(59);
    _la = _input->LA(1);
    if (!(_la == ifccParser::T__0

    || _la == ifccParser::TYPE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(60);
    match(ifccParser::VAR);
    setState(61);
    match(ifccParser::T__1);
    setState(63);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::TYPE) {
      setState(62);
      parameters();
    }
    setState(65);
    match(ifccParser::T__2);
    setState(66);
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
    setState(68);
    _la = _input->LA(1);
    if (!(_la == ifccParser::T__0

    || _la == ifccParser::TYPE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(69);
    match(ifccParser::VAR);
    setState(70);
    match(ifccParser::T__1);
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::TYPE) {
      setState(71);
      parameters();
    }
    setState(74);
    match(ifccParser::T__2);
    setState(75);
    match(ifccParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StaticVariableContext ------------------------------------------------------------------

ifccParser::StaticVariableContext::StaticVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::StaticVariableContext::TYPE() {
  return getToken(ifccParser::TYPE, 0);
}

tree::TerminalNode* ifccParser::StaticVariableContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::StaticVariableContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

tree::TerminalNode* ifccParser::StaticVariableContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
}

tree::TerminalNode* ifccParser::StaticVariableContext::STATIC() {
  return getToken(ifccParser::STATIC, 0);
}


size_t ifccParser::StaticVariableContext::getRuleIndex() const {
  return ifccParser::RuleStaticVariable;
}

void ifccParser::StaticVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStaticVariable(this);
}

void ifccParser::StaticVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStaticVariable(this);
}


std::any ifccParser::StaticVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStaticVariable(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::StaticVariableContext* ifccParser::staticVariable() {
  StaticVariableContext *_localctx = _tracker.createInstance<StaticVariableContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleStaticVariable);
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
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::STATIC) {
      setState(77);
      match(ifccParser::STATIC);
    }
    setState(80);
    match(ifccParser::TYPE);
    setState(81);
    match(ifccParser::VAR);
    setState(82);
    match(ifccParser::T__3);
    setState(83);
    match(ifccParser::CONST);
    setState(84);
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
  enterRule(_localctx, 10, ifccParser::RuleParameters);
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
    setState(86);
    parameter();
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__4) {
      setState(87);
      match(ifccParser::T__4);
      setState(88);
      parameter();
      setState(93);
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
  enterRule(_localctx, 12, ifccParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(ifccParser::TYPE);
    setState(95);
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
  enterRule(_localctx, 14, ifccParser::RuleArguments);
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
    argument();
    setState(102);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__4) {
      setState(98);
      match(ifccParser::T__4);
      setState(99);
      argument();
      setState(104);
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
  enterRule(_localctx, 16, ifccParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
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
  enterRule(_localctx, 18, ifccParser::RuleBlock);
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
    setState(107);
    match(ifccParser::T__5);
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__1)
      | (1ULL << ifccParser::T__5)
      | (1ULL << ifccParser::T__7)
      | (1ULL << ifccParser::T__8)
      | (1ULL << ifccParser::T__9)
      | (1ULL << ifccParser::T__10)
      | (1ULL << ifccParser::SEMICOLON)
      | (1ULL << ifccParser::IF)
      | (1ULL << ifccParser::WHILE)
      | (1ULL << ifccParser::RETURN)
      | (1ULL << ifccParser::TYPE)
      | (1ULL << ifccParser::INT_CONST)
      | (1ULL << ifccParser::CHAR_CONST)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(108);
      statement();
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(114);
    match(ifccParser::T__6);
   
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
  enterRule(_localctx, 20, ifccParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__1:
      case ifccParser::T__5:
      case ifccParser::T__7:
      case ifccParser::T__8:
      case ifccParser::T__9:
      case ifccParser::T__10:
      case ifccParser::SEMICOLON:
      case ifccParser::IF:
      case ifccParser::WHILE:
      case ifccParser::RETURN:
      case ifccParser::INT_CONST:
      case ifccParser::CHAR_CONST:
      case ifccParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(116);
        statementWithoutDeclaration();
        break;
      }

      case ifccParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(117);
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

ifccParser::ProcedureCallContext* ifccParser::StatementWithoutDeclarationContext::procedureCall() {
  return getRuleContext<ifccParser::ProcedureCallContext>(0);
}

ifccParser::BlockContext* ifccParser::StatementWithoutDeclarationContext::block() {
  return getRuleContext<ifccParser::BlockContext>(0);
}

ifccParser::EmptyContext* ifccParser::StatementWithoutDeclarationContext::empty() {
  return getRuleContext<ifccParser::EmptyContext>(0);
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
  enterRule(_localctx, 22, ifccParser::RuleStatementWithoutDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(121);
      ret();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(122);
      ifBlock();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(123);
      whileBlock();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(124);
      procedureCall();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(125);
      block();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(126);
      empty();
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

//----------------- ProcedureCallContext ------------------------------------------------------------------

ifccParser::ProcedureCallContext::ProcedureCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ProcedureCallContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::ProcedureCallContext::SEMICOLON() {
  return getToken(ifccParser::SEMICOLON, 0);
}

ifccParser::ArgumentsContext* ifccParser::ProcedureCallContext::arguments() {
  return getRuleContext<ifccParser::ArgumentsContext>(0);
}


size_t ifccParser::ProcedureCallContext::getRuleIndex() const {
  return ifccParser::RuleProcedureCall;
}

void ifccParser::ProcedureCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureCall(this);
}

void ifccParser::ProcedureCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureCall(this);
}


std::any ifccParser::ProcedureCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProcedureCall(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProcedureCallContext* ifccParser::procedureCall() {
  ProcedureCallContext *_localctx = _tracker.createInstance<ProcedureCallContext>(_ctx, getState());
  enterRule(_localctx, 24, ifccParser::RuleProcedureCall);
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
    setState(129);
    match(ifccParser::VAR);
    setState(130);
    match(ifccParser::T__1);
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__1)
      | (1ULL << ifccParser::T__7)
      | (1ULL << ifccParser::T__8)
      | (1ULL << ifccParser::T__9)
      | (1ULL << ifccParser::T__10)
      | (1ULL << ifccParser::INT_CONST)
      | (1ULL << ifccParser::CHAR_CONST)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(131);
      arguments();
    }
    setState(134);
    match(ifccParser::T__2);
    setState(135);
    match(ifccParser::SEMICOLON);
   
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

ifccParser::ExpContext* ifccParser::EmptyContext::exp() {
  return getRuleContext<ifccParser::ExpContext>(0);
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
  enterRule(_localctx, 26, ifccParser::RuleEmpty);
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
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__1)
      | (1ULL << ifccParser::T__7)
      | (1ULL << ifccParser::T__8)
      | (1ULL << ifccParser::T__9)
      | (1ULL << ifccParser::T__10)
      | (1ULL << ifccParser::INT_CONST)
      | (1ULL << ifccParser::CHAR_CONST)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(137);
      exp();
    }
    setState(140);
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

ifccParser::ExpContext* ifccParser::IfBlockContext::exp() {
  return getRuleContext<ifccParser::ExpContext>(0);
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
  enterRule(_localctx, 28, ifccParser::RuleIfBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(ifccParser::IF);
    setState(143);
    match(ifccParser::T__1);
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(144);
      exp();
      break;
    }

    case 2: {
      setState(145);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(148);
    match(ifccParser::T__2);
    setState(149);
    statementWithoutDeclaration();
    setState(151);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(150);
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
  enterRule(_localctx, 30, ifccParser::RuleElseBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(ifccParser::ELSE);
    setState(154);
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

ifccParser::StatementWithoutDeclarationContext* ifccParser::WhileBlockContext::statementWithoutDeclaration() {
  return getRuleContext<ifccParser::StatementWithoutDeclarationContext>(0);
}

ifccParser::ExpContext* ifccParser::WhileBlockContext::exp() {
  return getRuleContext<ifccParser::ExpContext>(0);
}

ifccParser::ExpAssignmentContext* ifccParser::WhileBlockContext::expAssignment() {
  return getRuleContext<ifccParser::ExpAssignmentContext>(0);
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
  enterRule(_localctx, 32, ifccParser::RuleWhileBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(ifccParser::WHILE);
    setState(157);
    match(ifccParser::T__1);
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(158);
      exp();
      break;
    }

    case 2: {
      setState(159);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(162);
    match(ifccParser::T__2);
    setState(163);
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

ifccParser::ExpContext* ifccParser::RetContext::exp() {
  return getRuleContext<ifccParser::ExpContext>(0);
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
  enterRule(_localctx, 34, ifccParser::RuleRet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(ifccParser::RETURN);
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(166);
      exp();
      break;
    }

    case 2: {
      setState(167);
      expAssignment();
      break;
    }

    default:
      break;
    }
    setState(170);
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
  enterRule(_localctx, 36, ifccParser::RuleDeclaration);
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
    setState(172);
    match(ifccParser::TYPE);
    setState(173);
    rawDeclaration();
    setState(178);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__4) {
      setState(174);
      match(ifccParser::T__4);
      setState(175);
      rawDeclaration();
      setState(180);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(181);
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

ifccParser::ExpContext* ifccParser::RawDeclarationContext::exp() {
  return getRuleContext<ifccParser::ExpContext>(0);
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
  enterRule(_localctx, 38, ifccParser::RuleRawDeclaration);
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
    setState(183);
    match(ifccParser::VAR);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__3) {
      setState(184);
      match(ifccParser::T__3);
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(185);
          match(ifccParser::VAR);
          setState(186);
          match(ifccParser::T__3); 
        }
        setState(191);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      }
      setState(192);
      exp();
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

ifccParser::ExpContext* ifccParser::ExpAssignmentContext::exp() {
  return getRuleContext<ifccParser::ExpContext>(0);
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
  enterRule(_localctx, 40, ifccParser::RuleExpAssignment);

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
    setState(197); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(195);
              match(ifccParser::VAR);
              setState(196);
              match(ifccParser::T__3);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(199); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(201);
    exp();
   
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
  enterRule(_localctx, 42, ifccParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    expAssignment();
    setState(204);
    match(ifccParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

ifccParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ExpressionContext* ifccParser::ExpContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}


size_t ifccParser::ExpContext::getRuleIndex() const {
  return ifccParser::RuleExp;
}

void ifccParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void ifccParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ifccListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


std::any ifccParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpContext* ifccParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 44, ifccParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    expression(0);
   
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

tree::TerminalNode* ifccParser::ConstantContext::INT_CONST() {
  return getToken(ifccParser::INT_CONST, 0);
}

tree::TerminalNode* ifccParser::ConstantContext::CHAR_CONST() {
  return getToken(ifccParser::CHAR_CONST, 0);
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, ifccParser::RuleExpression, precedence);

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
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(209);
      match(ifccParser::VAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(210);
      _la = _input->LA(1);
      if (!(_la == ifccParser::INT_CONST

      || _la == ifccParser::CHAR_CONST)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(211);
      match(ifccParser::T__1);
      setState(214);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(212);
        expression(0);
        break;
      }

      case 2: {
        setState(213);
        expAssignment();
        break;
      }

      default:
        break;
      }
      setState(216);
      match(ifccParser::T__2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(218);
      match(ifccParser::VAR);
      setState(219);
      match(ifccParser::T__1);
      setState(221);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ifccParser::T__1)
        | (1ULL << ifccParser::T__7)
        | (1ULL << ifccParser::T__8)
        | (1ULL << ifccParser::T__9)
        | (1ULL << ifccParser::T__10)
        | (1ULL << ifccParser::INT_CONST)
        | (1ULL << ifccParser::CHAR_CONST)
        | (1ULL << ifccParser::VAR))) != 0)) {
        setState(220);
        arguments();
      }
      setState(223);
      match(ifccParser::T__2);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(224);
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
      setState(225);
      expression(11);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(260);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(258);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<TimesDivModuloContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(228);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(229);
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
          setState(230);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(231);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(232);
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
          setState(233);
          expression(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ShiftContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(234);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(235);
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
          setState(236);
          expression(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(237);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(238);
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
          setState(239);
          expression(8);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(240);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(241);
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
          setState(242);
          expression(7);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitwiseAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(243);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(244);
          antlrcpp::downCast<BitwiseAndContext *>(_localctx)->op = match(ifccParser::T__22);
          setState(245);
          expression(6);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseXorContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(246);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(247);
          antlrcpp::downCast<BitwiseXorContext *>(_localctx)->op = match(ifccParser::T__23);
          setState(248);
          expression(5);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(249);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(250);
          antlrcpp::downCast<BitwiseOrContext *>(_localctx)->op = match(ifccParser::T__24);
          setState(251);
          expression(4);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicalAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(252);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(253);
          antlrcpp::downCast<LogicalAndContext *>(_localctx)->op = match(ifccParser::T__25);
          setState(254);
          expression(3);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(255);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(256);
          antlrcpp::downCast<LogicalOrContext *>(_localctx)->op = match(ifccParser::T__26);
          setState(257);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(262);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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
    case 23: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
