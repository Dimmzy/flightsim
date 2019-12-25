#include "flightSim.h"

void flightSim::run() {
  this->varManager = new VariableManager();
  this->generateMap();
  std::vector<std::string> lexed = lexer::lex(this->fileName);
  int index = 0;
  while (index < lexed.size()) {
    if (this->commandsMap.find(lexed[index]) != this->commandsMap.end()) {
      Command* c = this->commandsMap.find(lexed[index])->second;
      index++;
      // subvector
      auto first = lexed.begin() + index;
      auto last = lexed.begin() + lexed.size();
      index += c->execute(std::vector<std::string>(first,last));
    } else {
      if (this->varManager.)
    }
  }
}

void flightSim::generateMap() {
  this->commandsMap["openDataServer"] = new OpenServer();
  this->commandsMap["connectControlClient"] = new ConnectServer();
  this->commandsMap["var"] = new DefineVar(*this->varManager);
  this->commandsMap["Sleep"] = new Sleep();
  this->commandsMap["Print"] = new Print();
}