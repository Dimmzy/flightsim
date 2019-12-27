#ifndef FLIGHTSIM__LEXER_H_
#define FLIGHTSIM__LEXER_H_
#include "flightSim.h"

class lexer {
 public:
  static std::vector<std::string> lex(std::string file);
  static void lexingTokens(std::vector<std::string>& vectorString, std::ifstream& in_file);
};

#endif //FLIGHTSIM__LEXER_H_
