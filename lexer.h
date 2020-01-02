#ifndef FLIGHTSIM__LEXER_H_
#define FLIGHTSIM__LEXER_H_

#include "flightSim.h"

/**
 * The lexer class handles lexing and outputting a vector of strings from the file we're supposed to parse.
 */
class lexer {
 public:
  static std::vector<std::string> lex(std::string file);
  static void lexingTokens(std::vector<std::string>& vectorString, std::ifstream& in_file);
  static void postLexing(std::vector<std::string>& vectorOfTokens);
};

#endif //FLIGHTSIM__LEXER_H_
