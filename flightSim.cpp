#include "flightSim.h"

void flightSim::run() {
  this->varManager = new VariableManager();
  this->generateMap();
  std::vector<std::string> tokens = lexer::lex(this->fileName);
  int index = 0;
  while (index < tokens.size()) {
    Command* command = commandsMap.at(tokens[index]);
    if (command != nullptr) {
      index += command->execute(tokens,index);
    } else if (this->varManager->getSymbolTable().find(tokens[index]) != this->varManager->getSymbolTable().end()) {
      map<std::string, Variable*> symTable = this->varManager->getSymbolTable();
      Expression* exp = interpreter->interpret(tokens[index + 1]);
      symTable.at(tokens[index])->setValue(exp->calculate());
      client->sendUpdate("set " + symTable.at(tokens[index])->getPath() + " " +
      to_string(symTable.at(tokens[index])->getValue()) + "\r\n");
    }
  }
}

void flightSim::generateMap() {
  this->commandsMap["openDataServer"] = new OpenServer(this->varManager);
  this->commandsMap["connectControlClient"] = this->client;
  this->commandsMap["var"] = new DefineVar(this->varManager);
  this->commandsMap["Sleep"] = new Sleep();
  this->commandsMap["Print"] = new Print();
}