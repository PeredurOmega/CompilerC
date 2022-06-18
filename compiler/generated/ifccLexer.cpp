
// Generated from /home/mathis/IdeaProjects/CompilerC/compiler/ifcc.g4 by ANTLR 4.10.1


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
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "SEMICOLON", "IF", "ELSE", "RETURN", "TYPE", "COMMENT", 
      "CONST", "VAR", "DIRECTIVE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'void'", "'('", "')'", "','", "'{'", "'}'", "'='", "'-'", "'!'", 
      "'+'", "'~'", "'*'", "'/'", "'%'", "'<<'", "'>>'", "'<'", "'<='", 
      "'>='", "'>'", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", 
      "';'", "'if'", "'else'", "'return'", "'int'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "SEMICOLON", "IF", "ELSE", 
      "RETURN", "TYPE", "COMMENT", "CONST", "VAR", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,37,217,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,
  	5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,
  	13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,18,1,
  	18,1,18,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,
  	24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,29,1,
  	29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,
  	31,1,32,1,32,1,32,1,32,5,32,166,8,32,10,32,12,32,169,9,32,1,32,1,32,1,
  	32,1,32,1,32,1,32,5,32,177,8,32,10,32,12,32,180,9,32,1,32,1,32,1,32,3,
  	32,185,8,32,3,32,187,8,32,1,32,1,32,1,33,4,33,192,8,33,11,33,12,33,193,
  	1,34,1,34,5,34,198,8,34,10,34,12,34,201,9,34,1,35,1,35,5,35,205,8,35,
  	10,35,12,35,208,9,35,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,3,167,178,
  	206,0,37,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,
  	13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,
  	49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,
  	36,73,37,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,5,0,36,36,48,57,65,90,
  	95,95,97,122,3,0,9,10,13,13,32,32,223,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,
  	0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,
  	17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,
  	0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,
  	0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,
  	49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,
  	0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,
  	0,0,71,1,0,0,0,0,73,1,0,0,0,1,75,1,0,0,0,3,80,1,0,0,0,5,82,1,0,0,0,7,
  	84,1,0,0,0,9,86,1,0,0,0,11,88,1,0,0,0,13,90,1,0,0,0,15,92,1,0,0,0,17,
  	94,1,0,0,0,19,96,1,0,0,0,21,98,1,0,0,0,23,100,1,0,0,0,25,102,1,0,0,0,
  	27,104,1,0,0,0,29,106,1,0,0,0,31,109,1,0,0,0,33,112,1,0,0,0,35,114,1,
  	0,0,0,37,117,1,0,0,0,39,120,1,0,0,0,41,122,1,0,0,0,43,125,1,0,0,0,45,
  	128,1,0,0,0,47,130,1,0,0,0,49,132,1,0,0,0,51,134,1,0,0,0,53,137,1,0,0,
  	0,55,140,1,0,0,0,57,142,1,0,0,0,59,145,1,0,0,0,61,150,1,0,0,0,63,157,
  	1,0,0,0,65,186,1,0,0,0,67,191,1,0,0,0,69,195,1,0,0,0,71,202,1,0,0,0,73,
  	213,1,0,0,0,75,76,5,118,0,0,76,77,5,111,0,0,77,78,5,105,0,0,78,79,5,100,
  	0,0,79,2,1,0,0,0,80,81,5,40,0,0,81,4,1,0,0,0,82,83,5,41,0,0,83,6,1,0,
  	0,0,84,85,5,44,0,0,85,8,1,0,0,0,86,87,5,123,0,0,87,10,1,0,0,0,88,89,5,
  	125,0,0,89,12,1,0,0,0,90,91,5,61,0,0,91,14,1,0,0,0,92,93,5,45,0,0,93,
  	16,1,0,0,0,94,95,5,33,0,0,95,18,1,0,0,0,96,97,5,43,0,0,97,20,1,0,0,0,
  	98,99,5,126,0,0,99,22,1,0,0,0,100,101,5,42,0,0,101,24,1,0,0,0,102,103,
  	5,47,0,0,103,26,1,0,0,0,104,105,5,37,0,0,105,28,1,0,0,0,106,107,5,60,
  	0,0,107,108,5,60,0,0,108,30,1,0,0,0,109,110,5,62,0,0,110,111,5,62,0,0,
  	111,32,1,0,0,0,112,113,5,60,0,0,113,34,1,0,0,0,114,115,5,60,0,0,115,116,
  	5,61,0,0,116,36,1,0,0,0,117,118,5,62,0,0,118,119,5,61,0,0,119,38,1,0,
  	0,0,120,121,5,62,0,0,121,40,1,0,0,0,122,123,5,61,0,0,123,124,5,61,0,0,
  	124,42,1,0,0,0,125,126,5,33,0,0,126,127,5,61,0,0,127,44,1,0,0,0,128,129,
  	5,38,0,0,129,46,1,0,0,0,130,131,5,94,0,0,131,48,1,0,0,0,132,133,5,124,
  	0,0,133,50,1,0,0,0,134,135,5,38,0,0,135,136,5,38,0,0,136,52,1,0,0,0,137,
  	138,5,124,0,0,138,139,5,124,0,0,139,54,1,0,0,0,140,141,5,59,0,0,141,56,
  	1,0,0,0,142,143,5,105,0,0,143,144,5,102,0,0,144,58,1,0,0,0,145,146,5,
  	101,0,0,146,147,5,108,0,0,147,148,5,115,0,0,148,149,5,101,0,0,149,60,
  	1,0,0,0,150,151,5,114,0,0,151,152,5,101,0,0,152,153,5,116,0,0,153,154,
  	5,117,0,0,154,155,5,114,0,0,155,156,5,110,0,0,156,62,1,0,0,0,157,158,
  	5,105,0,0,158,159,5,110,0,0,159,160,5,116,0,0,160,64,1,0,0,0,161,162,
  	5,47,0,0,162,163,5,42,0,0,163,167,1,0,0,0,164,166,9,0,0,0,165,164,1,0,
  	0,0,166,169,1,0,0,0,167,168,1,0,0,0,167,165,1,0,0,0,168,170,1,0,0,0,169,
  	167,1,0,0,0,170,171,5,42,0,0,171,187,5,47,0,0,172,173,5,47,0,0,173,174,
  	5,47,0,0,174,178,1,0,0,0,175,177,9,0,0,0,176,175,1,0,0,0,177,180,1,0,
  	0,0,178,179,1,0,0,0,178,176,1,0,0,0,179,184,1,0,0,0,180,178,1,0,0,0,181,
  	185,5,10,0,0,182,183,5,13,0,0,183,185,5,10,0,0,184,181,1,0,0,0,184,182,
  	1,0,0,0,185,187,1,0,0,0,186,161,1,0,0,0,186,172,1,0,0,0,187,188,1,0,0,
  	0,188,189,6,32,0,0,189,66,1,0,0,0,190,192,7,0,0,0,191,190,1,0,0,0,192,
  	193,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,68,1,0,0,0,195,199,7,
  	1,0,0,196,198,7,2,0,0,197,196,1,0,0,0,198,201,1,0,0,0,199,197,1,0,0,0,
  	199,200,1,0,0,0,200,70,1,0,0,0,201,199,1,0,0,0,202,206,5,35,0,0,203,205,
  	9,0,0,0,204,203,1,0,0,0,205,208,1,0,0,0,206,207,1,0,0,0,206,204,1,0,0,
  	0,207,209,1,0,0,0,208,206,1,0,0,0,209,210,5,10,0,0,210,211,1,0,0,0,211,
  	212,6,35,0,0,212,72,1,0,0,0,213,214,7,3,0,0,214,215,1,0,0,0,215,216,6,
  	36,1,0,216,74,1,0,0,0,8,0,167,178,184,186,193,199,206,2,6,0,0,0,1,0
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
