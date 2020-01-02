#include "flightSim.h"
#include <utility>

void flightSim::run() {
  this->generateMap();
  std::vector<std::string> tokens = lexer::lex(this->fileName);
  int index = 0;
  while (index < tokens.size()) {
    std::cout << "Command Number " + std::to_string(index) << std::endl;
    if (commandsMap.find(tokens[index]) != commandsMap.end()) {
      Command *command = commandsMap.at(tokens[index]);
      index += command->execute(tokens, index);
    }
  }
}

void flightSim::generateMap() {
  this->commandsMap["openDataServer"] = new OpenServer(this->varManager, this->expressionInterpreter);
  this->commandsMap["connectControlClient"] = this->client;
  this->commandsMap["var"] = new DefineVar(this->varManager, &this->commandsMap,this->changeCommand);
  this->commandsMap["Sleep"] = new Sleep(this->expressionInterpreter);
  this->commandsMap["Print"] = new Print();
}
flightSim::flightSim(std::string name) {
  this->fileName = std::move(name);
  this->varManager = new VariableManager();
  this->expressionInterpreter = new Interpreter(this->varManager);
  this->client = new OpenClient(this->expressionInterpreter);
  this->changeCommand = new ChangeVar(this->varManager,this->expressionInterpreter,this->client);
}
