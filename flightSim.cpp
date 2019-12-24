#include "flightSim.h"

void flightSim::run() {
    this->generateMap();
    std::vector<std::string> lexed = lexer::lex(this->fileName);
}

void flightSim::generateMap() {
    this->commandsMap["openDataServer"] = new OpenServer();
    this->commandsMap["connectControlClient"] = new ConnectServer();
    this->commandsMap["var"] = new DefineVar();
    this->commandsMap["Sleep"] = new Sleep();
    this->commandsMap["Print"] = new Print();
}