
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
      "T__9", "T__10", "T__11", "RETURN", "TYPE", "CONST", "VAR", "COMMENT", 
      "DIRECTIVE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'main'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'*'", 
      "'/'", "'+'", "'-'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "RETURN", "TYPE", 
      "CONST", "VAR", "COMMENT", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,19,118,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,
  	10,1,10,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,
  	13,1,14,4,14,79,8,14,11,14,12,14,80,1,15,1,15,5,15,85,8,15,10,15,12,15,
  	88,9,15,1,16,1,16,1,16,1,16,5,16,94,8,16,10,16,12,16,97,9,16,1,16,1,16,
  	1,16,1,16,1,16,1,17,1,17,5,17,106,8,17,10,17,12,17,109,9,17,1,17,1,17,
  	1,17,1,17,1,18,1,18,1,18,1,18,2,95,107,0,19,1,1,3,2,5,3,7,4,9,5,11,6,
  	13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,
  	37,19,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,5,0,36,36,48,57,65,90,95,
  	95,97,122,3,0,9,10,13,13,32,32,121,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,
  	1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,
  	0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,
  	1,39,1,0,0,0,3,44,1,0,0,0,5,46,1,0,0,0,7,48,1,0,0,0,9,50,1,0,0,0,11,52,
  	1,0,0,0,13,54,1,0,0,0,15,56,1,0,0,0,17,58,1,0,0,0,19,60,1,0,0,0,21,62,
  	1,0,0,0,23,64,1,0,0,0,25,66,1,0,0,0,27,73,1,0,0,0,29,78,1,0,0,0,31,82,
  	1,0,0,0,33,89,1,0,0,0,35,103,1,0,0,0,37,114,1,0,0,0,39,40,5,109,0,0,40,
  	41,5,97,0,0,41,42,5,105,0,0,42,43,5,110,0,0,43,2,1,0,0,0,44,45,5,40,0,
  	0,45,4,1,0,0,0,46,47,5,41,0,0,47,6,1,0,0,0,48,49,5,123,0,0,49,8,1,0,0,
  	0,50,51,5,125,0,0,51,10,1,0,0,0,52,53,5,59,0,0,53,12,1,0,0,0,54,55,5,
  	44,0,0,55,14,1,0,0,0,56,57,5,61,0,0,57,16,1,0,0,0,58,59,5,42,0,0,59,18,
  	1,0,0,0,60,61,5,47,0,0,61,20,1,0,0,0,62,63,5,43,0,0,63,22,1,0,0,0,64,
  	65,5,45,0,0,65,24,1,0,0,0,66,67,5,114,0,0,67,68,5,101,0,0,68,69,5,116,
  	0,0,69,70,5,117,0,0,70,71,5,114,0,0,71,72,5,110,0,0,72,26,1,0,0,0,73,
  	74,5,105,0,0,74,75,5,110,0,0,75,76,5,116,0,0,76,28,1,0,0,0,77,79,7,0,
  	0,0,78,77,1,0,0,0,79,80,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,0,81,30,1,0,
  	0,0,82,86,7,1,0,0,83,85,7,2,0,0,84,83,1,0,0,0,85,88,1,0,0,0,86,84,1,0,
  	0,0,86,87,1,0,0,0,87,32,1,0,0,0,88,86,1,0,0,0,89,90,5,47,0,0,90,91,5,
  	42,0,0,91,95,1,0,0,0,92,94,9,0,0,0,93,92,1,0,0,0,94,97,1,0,0,0,95,96,
  	1,0,0,0,95,93,1,0,0,0,96,98,1,0,0,0,97,95,1,0,0,0,98,99,5,42,0,0,99,100,
  	5,47,0,0,100,101,1,0,0,0,101,102,6,16,0,0,102,34,1,0,0,0,103,107,5,35,
  	0,0,104,106,9,0,0,0,105,104,1,0,0,0,106,109,1,0,0,0,107,108,1,0,0,0,107,
  	105,1,0,0,0,108,110,1,0,0,0,109,107,1,0,0,0,110,111,5,10,0,0,111,112,
  	1,0,0,0,112,113,6,17,0,0,113,36,1,0,0,0,114,115,7,3,0,0,115,116,1,0,0,
  	0,116,117,6,18,1,0,117,38,1,0,0,0,5,0,80,86,95,107,2,6,0,0,0,1,0
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
