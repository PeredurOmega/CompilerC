
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
      "T__17", "T__18", "T__19", "IF", "ELSE", "RETURN", "TYPE", "CONST", 
      "VAR", "COMMENT", "DIRECTIVE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'main'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'*'", 
      "'/'", "'%'", "'+'", "'-'", "'!'", "'<'", "'<='", "'=='", "'!='", 
      "'>='", "'>'", "'if'", "'else'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "IF", "ELSE", "RETURN", "TYPE", "CONST", "VAR", "COMMENT", 
      "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,29,166,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,
  	1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,
  	14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,
  	19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,23,1,23,1,23,1,23,1,24,4,24,127,8,24,11,24,12,24,128,1,
  	25,1,25,5,25,133,8,25,10,25,12,25,136,9,25,1,26,1,26,1,26,1,26,5,26,142,
  	8,26,10,26,12,26,145,9,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,5,27,154,
  	8,27,10,27,12,27,157,9,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,2,143,
  	155,0,29,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,
  	13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,
  	49,25,51,26,53,27,55,28,57,29,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,
  	5,0,36,36,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,169,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,
  	0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,
  	0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,
  	35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,
  	0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,
  	0,0,57,1,0,0,0,1,59,1,0,0,0,3,64,1,0,0,0,5,66,1,0,0,0,7,68,1,0,0,0,9,
  	70,1,0,0,0,11,72,1,0,0,0,13,74,1,0,0,0,15,76,1,0,0,0,17,78,1,0,0,0,19,
  	80,1,0,0,0,21,82,1,0,0,0,23,84,1,0,0,0,25,86,1,0,0,0,27,88,1,0,0,0,29,
  	90,1,0,0,0,31,92,1,0,0,0,33,95,1,0,0,0,35,98,1,0,0,0,37,101,1,0,0,0,39,
  	104,1,0,0,0,41,106,1,0,0,0,43,109,1,0,0,0,45,114,1,0,0,0,47,121,1,0,0,
  	0,49,126,1,0,0,0,51,130,1,0,0,0,53,137,1,0,0,0,55,151,1,0,0,0,57,162,
  	1,0,0,0,59,60,5,109,0,0,60,61,5,97,0,0,61,62,5,105,0,0,62,63,5,110,0,
  	0,63,2,1,0,0,0,64,65,5,40,0,0,65,4,1,0,0,0,66,67,5,41,0,0,67,6,1,0,0,
  	0,68,69,5,123,0,0,69,8,1,0,0,0,70,71,5,125,0,0,71,10,1,0,0,0,72,73,5,
  	59,0,0,73,12,1,0,0,0,74,75,5,44,0,0,75,14,1,0,0,0,76,77,5,61,0,0,77,16,
  	1,0,0,0,78,79,5,42,0,0,79,18,1,0,0,0,80,81,5,47,0,0,81,20,1,0,0,0,82,
  	83,5,37,0,0,83,22,1,0,0,0,84,85,5,43,0,0,85,24,1,0,0,0,86,87,5,45,0,0,
  	87,26,1,0,0,0,88,89,5,33,0,0,89,28,1,0,0,0,90,91,5,60,0,0,91,30,1,0,0,
  	0,92,93,5,60,0,0,93,94,5,61,0,0,94,32,1,0,0,0,95,96,5,61,0,0,96,97,5,
  	61,0,0,97,34,1,0,0,0,98,99,5,33,0,0,99,100,5,61,0,0,100,36,1,0,0,0,101,
  	102,5,62,0,0,102,103,5,61,0,0,103,38,1,0,0,0,104,105,5,62,0,0,105,40,
  	1,0,0,0,106,107,5,105,0,0,107,108,5,102,0,0,108,42,1,0,0,0,109,110,5,
  	101,0,0,110,111,5,108,0,0,111,112,5,115,0,0,112,113,5,101,0,0,113,44,
  	1,0,0,0,114,115,5,114,0,0,115,116,5,101,0,0,116,117,5,116,0,0,117,118,
  	5,117,0,0,118,119,5,114,0,0,119,120,5,110,0,0,120,46,1,0,0,0,121,122,
  	5,105,0,0,122,123,5,110,0,0,123,124,5,116,0,0,124,48,1,0,0,0,125,127,
  	7,0,0,0,126,125,1,0,0,0,127,128,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,
  	0,129,50,1,0,0,0,130,134,7,1,0,0,131,133,7,2,0,0,132,131,1,0,0,0,133,
  	136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,52,1,0,0,0,136,134,1,
  	0,0,0,137,138,5,47,0,0,138,139,5,42,0,0,139,143,1,0,0,0,140,142,9,0,0,
  	0,141,140,1,0,0,0,142,145,1,0,0,0,143,144,1,0,0,0,143,141,1,0,0,0,144,
  	146,1,0,0,0,145,143,1,0,0,0,146,147,5,42,0,0,147,148,5,47,0,0,148,149,
  	1,0,0,0,149,150,6,26,0,0,150,54,1,0,0,0,151,155,5,35,0,0,152,154,9,0,
  	0,0,153,152,1,0,0,0,154,157,1,0,0,0,155,156,1,0,0,0,155,153,1,0,0,0,156,
  	158,1,0,0,0,157,155,1,0,0,0,158,159,5,10,0,0,159,160,1,0,0,0,160,161,
  	6,27,0,0,161,56,1,0,0,0,162,163,7,3,0,0,163,164,1,0,0,0,164,165,6,28,
  	1,0,165,58,1,0,0,0,5,0,128,134,143,155,2,6,0,0,0,1,0
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
