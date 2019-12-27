#include "flightSim.h"

void flightSim::run() {
  this->varManager = new VariableManager();
  this->generateMap();
  std::vector<std::string> tokens = lexer::lex(this->fileName);
  int index = 0;
  std::vector<std::string> serverags = {"5400"};
  this->commandsMap.at("openDataServer")->execute(serverags);
  /*
  while (index < tokens.size()) {
    if (this->commandsMap.find(tokens[index]) != this->commandsMap.end()) {
      Command* c = this->commandsMap.find(tokens[index])->second;
      index++;
      // subvector
      auto first = tokens.begin() + index;
      auto last = tokens.begin() + tokens.size();
      index += c->execute(std::vector<std::string>(first,last));
    } else {
      // Find an already set variable.
      if (this->varManager->getSymbolTable().find(tokens[index]) != this->varManager->getSymbolTable().end())
        // Implement Expression Evaluation from Ex1
    }
  }*/
}

void flightSim::generateMap() {
  this->commandsMap["openDataServer"] = new OpenServer(this->varManager);
  this->commandsMap["connectControlClient"] = new OpenClient();
  this->commandsMap["var"] = new DefineVar(*this->varManager);
  this->commandsMap["Sleep"] = new Sleep();
  this->commandsMap["Print"] = new Print();
}