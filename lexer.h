//
// Created by dima on 16/12/2019.
//

#ifndef FLIGHTSIM__LEXER_H_
#define FLIGHTSIM__LEXER_H_
#include "flightSim.h"

class lexer {
 public:
  static std::vector<std::string> lex(std::string file);
  static void lexingTokens(std::vector<std::string>& vectorString, std::ifstream& in_file);
  static void postLexing(std::vector<std::string>& vectorOfTokens);
};

#endif //FLIGHTSIM__LEXER_H_
