
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1


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
      "T__17", "T__18", "IF", "ELSE", "RETURN", "TYPE", "CONST", "VAR", 
      "COMMENT", "DIRECTIVE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'main'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'*'", 
      "'/'", "'%'", "'+'", "'-'", "'<'", "'<='", "'=='", "'!='", "'>='", 
      "'>'", "'if'", "'else'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "IF", "ELSE", "RETURN", "TYPE", "CONST", "VAR", "COMMENT", 
      "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,28,162,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,
  	1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,
  	7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,
  	14,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,
  	19,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,
  	22,1,22,1,22,1,23,4,23,123,8,23,11,23,12,23,124,1,24,1,24,5,24,129,8,
  	24,10,24,12,24,132,9,24,1,25,1,25,1,25,1,25,5,25,138,8,25,10,25,12,25,
  	141,9,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,5,26,150,8,26,10,26,12,26,
  	153,9,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,2,139,151,0,28,1,1,3,
  	2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,
  	31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,
  	27,55,28,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,5,0,36,36,48,57,65,90,
  	95,95,97,122,3,0,9,10,13,13,32,32,165,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,
  	0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,
  	17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,
  	0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,
  	0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,
  	49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,1,57,1,0,0,0,3,62,1,
  	0,0,0,5,64,1,0,0,0,7,66,1,0,0,0,9,68,1,0,0,0,11,70,1,0,0,0,13,72,1,0,
  	0,0,15,74,1,0,0,0,17,76,1,0,0,0,19,78,1,0,0,0,21,80,1,0,0,0,23,82,1,0,
  	0,0,25,84,1,0,0,0,27,86,1,0,0,0,29,88,1,0,0,0,31,91,1,0,0,0,33,94,1,0,
  	0,0,35,97,1,0,0,0,37,100,1,0,0,0,39,102,1,0,0,0,41,105,1,0,0,0,43,110,
  	1,0,0,0,45,117,1,0,0,0,47,122,1,0,0,0,49,126,1,0,0,0,51,133,1,0,0,0,53,
  	147,1,0,0,0,55,158,1,0,0,0,57,58,5,109,0,0,58,59,5,97,0,0,59,60,5,105,
  	0,0,60,61,5,110,0,0,61,2,1,0,0,0,62,63,5,40,0,0,63,4,1,0,0,0,64,65,5,
  	41,0,0,65,6,1,0,0,0,66,67,5,123,0,0,67,8,1,0,0,0,68,69,5,125,0,0,69,10,
  	1,0,0,0,70,71,5,59,0,0,71,12,1,0,0,0,72,73,5,44,0,0,73,14,1,0,0,0,74,
  	75,5,61,0,0,75,16,1,0,0,0,76,77,5,42,0,0,77,18,1,0,0,0,78,79,5,47,0,0,
  	79,20,1,0,0,0,80,81,5,37,0,0,81,22,1,0,0,0,82,83,5,43,0,0,83,24,1,0,0,
  	0,84,85,5,45,0,0,85,26,1,0,0,0,86,87,5,60,0,0,87,28,1,0,0,0,88,89,5,60,
  	0,0,89,90,5,61,0,0,90,30,1,0,0,0,91,92,5,61,0,0,92,93,5,61,0,0,93,32,
  	1,0,0,0,94,95,5,33,0,0,95,96,5,61,0,0,96,34,1,0,0,0,97,98,5,62,0,0,98,
  	99,5,61,0,0,99,36,1,0,0,0,100,101,5,62,0,0,101,38,1,0,0,0,102,103,5,105,
  	0,0,103,104,5,102,0,0,104,40,1,0,0,0,105,106,5,101,0,0,106,107,5,108,
  	0,0,107,108,5,115,0,0,108,109,5,101,0,0,109,42,1,0,0,0,110,111,5,114,
  	0,0,111,112,5,101,0,0,112,113,5,116,0,0,113,114,5,117,0,0,114,115,5,114,
  	0,0,115,116,5,110,0,0,116,44,1,0,0,0,117,118,5,105,0,0,118,119,5,110,
  	0,0,119,120,5,116,0,0,120,46,1,0,0,0,121,123,7,0,0,0,122,121,1,0,0,0,
  	123,124,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,48,1,0,0,0,126,130,
  	7,1,0,0,127,129,7,2,0,0,128,127,1,0,0,0,129,132,1,0,0,0,130,128,1,0,0,
  	0,130,131,1,0,0,0,131,50,1,0,0,0,132,130,1,0,0,0,133,134,5,47,0,0,134,
  	135,5,42,0,0,135,139,1,0,0,0,136,138,9,0,0,0,137,136,1,0,0,0,138,141,
  	1,0,0,0,139,140,1,0,0,0,139,137,1,0,0,0,140,142,1,0,0,0,141,139,1,0,0,
  	0,142,143,5,42,0,0,143,144,5,47,0,0,144,145,1,0,0,0,145,146,6,25,0,0,
  	146,52,1,0,0,0,147,151,5,35,0,0,148,150,9,0,0,0,149,148,1,0,0,0,150,153,
  	1,0,0,0,151,152,1,0,0,0,151,149,1,0,0,0,152,154,1,0,0,0,153,151,1,0,0,
  	0,154,155,5,10,0,0,155,156,1,0,0,0,156,157,6,26,0,0,157,54,1,0,0,0,158,
  	159,7,3,0,0,159,160,1,0,0,0,160,161,6,27,1,0,161,56,1,0,0,0,5,0,124,130,
  	139,151,2,6,0,0,0,1,0
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
