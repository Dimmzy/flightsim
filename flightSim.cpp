#include "flightSim.h"

void flightSim::run() {
  this->varManager = new VariableManager();
  this->generateMap();
  std::vector<std::string> tokens = lexer::lex(this->fileName);
  int index = 0;
  std::vector<std::string> serverags = {"5400"};
  this->varManager->addBoundTable("/sim/time/warp",new Variable(0, "/sim/time/warp"));
  this->varManager->addBoundTable("/engines/engine/rpm",new Variable(0,"/engines/engine/rpm"));
  this->commandsMap.at("openDataServer")->execute(serverags);

  this->varManager->addSymbol("throttle", new Variable(0,"/controls/engines/current-engine/throttle"));
  sleep(30000);
  this->client = new OpenClient();
  auto it = this->varManager->getSymbolTable().at("thorttle");
  it->setValue(1.00);
  this->client->sendUpdate("set " + it->getPath() + " " + std::to_string(it->getValue()) + "\r\n");

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
        this->varManager->getSymbolTable().at(tokens[index])->setValue(133);
        client->sendUpdate("set " + this->varManager->getSymbolTable().at(tokens[index])->getPath() + " " + "500" +
        "\r\n");
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