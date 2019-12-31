#include "flightSim.h"

#include <utility>
#define VAR_OFFSET 3;

void flightSim::run() {
  this->generateMap();
  std::vector<std::string> tokens = lexer::lex(this->fileName );
  int index = 0;
  while (index < tokens.size()) {
    std::cout << "Command Number " + std::to_string(index) << std::endl;
    Command* command = commandsMap.at(tokens[index]);
    if (command != nullptr) {
      index += command->execute(tokens,index);
    } else if (this->varManager->getSymbolTable().find(tokens[index]) != this->varManager->getSymbolTable().end()) {
      map<std::string, Variable*> symTable = this->varManager->getSymbolTable();
      Expression* exp = expressionInterpreter->interpret(tokens[index + 1]);
      symTable.at(tokens[index])->setValue(exp->calculate());
      client->sendUpdate("set " + symTable.at(tokens[index])->getPath() + " " +
      to_string(symTable.at(tokens[index])->getValue()) + "\r\n");
      index += VAR_OFFSET;
    }
  }
}

void flightSim::generateMap() {
  this->commandsMap["openDataServer"] = new OpenServer(this->varManager,this->expressionInterpreter);
  this->commandsMap["connectControlClient"] = this->client;
  this->commandsMap["var"] = new DefineVar(this->varManager);
  this->commandsMap["Sleep"] = new Sleep(this->expressionInterpreter);
  this->commandsMap["Print"] = new Print();
}
flightSim::flightSim(std::string name) {
  this->varManager = new VariableManager();
  this->expressionInterpreter = new Interpreter();
  this->fileName = std::move(name);
  this->client = new OpenClient(this->expressionInterpreter);
}
