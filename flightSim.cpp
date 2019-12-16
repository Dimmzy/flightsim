#include "flightSim.h"

void flightSim::run() {
  fstream file;
  file.open("fly.txt");
  vector<string> lexed = lexer::lex(file);
}
