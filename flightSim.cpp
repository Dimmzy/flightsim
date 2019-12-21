#include "flightSim.h"

void flightSim::run() {
  std::vector<std::string> lexed = lexer::lex(this->fileName);
}
void flightSim::generateMap() {
  std::vector<std::string> keys = {"openDataServer","connectControlClient","var","Sleep","Print"};
  std::vector<std::string> values = {"OpenServer","Connect","DefineVar","Sleep","Print"};
}