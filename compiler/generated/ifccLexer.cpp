
// Generated from /home/bmayouddup/CLionProjects/CompilerC/compiler/ifcc.g4 by ANTLR 4.10.1


#include "ifccLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct IfccLexerStaticData final {
  IfccLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccLexerStaticData(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData(IfccLexerStaticData&&) = delete;
  IfccLexerStaticData& operator=(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData& operator=(IfccLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag ifcclexerLexerOnceFlag;
IfccLexerStaticData *ifcclexerLexerStaticData = nullptr;

void ifcclexerLexerInitialize() {
  assert(ifcclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<IfccLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "RETURN", "TYPE", "CONST", "VAR", "COMMENT", "DIRECTIVE", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'main'", "'('", "')'", "'{'", "';'", "'}'", "','", "'='", "'*'", 
      "'/'", "'%'", "'+'", "'-'", "'<'", "'<='", "'=='", "'!='", "'>='", 
      "'>'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "RETURN", "TYPE", "CONST", "VAR", "COMMENT", "DIRECTIVE", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,26,150,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,
  	10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,
  	16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,20,1,20,1,20,1,20,1,21,4,21,111,8,21,11,21,12,21,112,1,22,1,22,5,
  	22,117,8,22,10,22,12,22,120,9,22,1,23,1,23,1,23,1,23,5,23,126,8,23,10,
  	23,12,23,129,9,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,5,24,138,8,24,10,
  	24,12,24,141,9,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,2,127,139,0,
  	26,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,
  	14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,
  	51,26,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,5,0,36,36,48,57,65,90,95,
  	95,97,122,3,0,9,10,13,13,32,32,153,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,
  	1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,
  	0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,
  	0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,
  	1,0,0,0,0,51,1,0,0,0,1,53,1,0,0,0,3,58,1,0,0,0,5,60,1,0,0,0,7,62,1,0,
  	0,0,9,64,1,0,0,0,11,66,1,0,0,0,13,68,1,0,0,0,15,70,1,0,0,0,17,72,1,0,
  	0,0,19,74,1,0,0,0,21,76,1,0,0,0,23,78,1,0,0,0,25,80,1,0,0,0,27,82,1,0,
  	0,0,29,84,1,0,0,0,31,87,1,0,0,0,33,90,1,0,0,0,35,93,1,0,0,0,37,96,1,0,
  	0,0,39,98,1,0,0,0,41,105,1,0,0,0,43,110,1,0,0,0,45,114,1,0,0,0,47,121,
  	1,0,0,0,49,135,1,0,0,0,51,146,1,0,0,0,53,54,5,109,0,0,54,55,5,97,0,0,
  	55,56,5,105,0,0,56,57,5,110,0,0,57,2,1,0,0,0,58,59,5,40,0,0,59,4,1,0,
  	0,0,60,61,5,41,0,0,61,6,1,0,0,0,62,63,5,123,0,0,63,8,1,0,0,0,64,65,5,
  	59,0,0,65,10,1,0,0,0,66,67,5,125,0,0,67,12,1,0,0,0,68,69,5,44,0,0,69,
  	14,1,0,0,0,70,71,5,61,0,0,71,16,1,0,0,0,72,73,5,42,0,0,73,18,1,0,0,0,
  	74,75,5,47,0,0,75,20,1,0,0,0,76,77,5,37,0,0,77,22,1,0,0,0,78,79,5,43,
  	0,0,79,24,1,0,0,0,80,81,5,45,0,0,81,26,1,0,0,0,82,83,5,60,0,0,83,28,1,
  	0,0,0,84,85,5,60,0,0,85,86,5,61,0,0,86,30,1,0,0,0,87,88,5,61,0,0,88,89,
  	5,61,0,0,89,32,1,0,0,0,90,91,5,33,0,0,91,92,5,61,0,0,92,34,1,0,0,0,93,
  	94,5,62,0,0,94,95,5,61,0,0,95,36,1,0,0,0,96,97,5,62,0,0,97,38,1,0,0,0,
  	98,99,5,114,0,0,99,100,5,101,0,0,100,101,5,116,0,0,101,102,5,117,0,0,
  	102,103,5,114,0,0,103,104,5,110,0,0,104,40,1,0,0,0,105,106,5,105,0,0,
  	106,107,5,110,0,0,107,108,5,116,0,0,108,42,1,0,0,0,109,111,7,0,0,0,110,
  	109,1,0,0,0,111,112,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,44,1,
  	0,0,0,114,118,7,1,0,0,115,117,7,2,0,0,116,115,1,0,0,0,117,120,1,0,0,0,
  	118,116,1,0,0,0,118,119,1,0,0,0,119,46,1,0,0,0,120,118,1,0,0,0,121,122,
  	5,47,0,0,122,123,5,42,0,0,123,127,1,0,0,0,124,126,9,0,0,0,125,124,1,0,
  	0,0,126,129,1,0,0,0,127,128,1,0,0,0,127,125,1,0,0,0,128,130,1,0,0,0,129,
  	127,1,0,0,0,130,131,5,42,0,0,131,132,5,47,0,0,132,133,1,0,0,0,133,134,
  	6,23,0,0,134,48,1,0,0,0,135,139,5,35,0,0,136,138,9,0,0,0,137,136,1,0,
  	0,0,138,141,1,0,0,0,139,140,1,0,0,0,139,137,1,0,0,0,140,142,1,0,0,0,141,
  	139,1,0,0,0,142,143,5,10,0,0,143,144,1,0,0,0,144,145,6,24,0,0,145,50,
  	1,0,0,0,146,147,7,3,0,0,147,148,1,0,0,0,148,149,6,25,1,0,149,52,1,0,0,
  	0,5,0,112,118,127,139,2,6,0,0,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifcclexerLexerStaticData = staticData.release();
}

}

ifccLexer::ifccLexer(CharStream *input) : Lexer(input) {
  ifccLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ifcclexerLexerStaticData->atn, ifcclexerLexerStaticData->decisionToDFA, ifcclexerLexerStaticData->sharedContextCache);
}

ifccLexer::~ifccLexer() {
  delete _interpreter;
}

std::string ifccLexer::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccLexer::getRuleNames() const {
  return ifcclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ifccLexer::getChannelNames() const {
  return ifcclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ifccLexer::getModeNames() const {
  return ifcclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ifccLexer::getVocabulary() const {
  return ifcclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccLexer::getSerializedATN() const {
  return ifcclexerLexerStaticData->serializedATN;
}

const atn::ATN& ifccLexer::getATN() const {
  return *ifcclexerLexerStaticData->atn;
}




void ifccLexer::initialize() {
  std::call_once(ifcclexerLexerOnceFlag, ifcclexerLexerInitialize);
}
