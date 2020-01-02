#include "flightSim.h"
#include <utility>

/**
 * The run function handles the loop that parses the vector of strings from the lexer and executes their actions.
 */
void flightSim::run() {
  // Generates the preliminary map of commands.
  this->generateMap();
  // Gets the lexed vector
  std::vector<std::string> tokens = lexer::lex(this->fileName);
  int index = 0;
  // Main loop
  while (index < tokens.size()) {
    std::cout << "Command Number " + std::to_string(index) << std::endl;
    if (commandsMap.find(tokens[index]) != commandsMap.end()) {
      Command *command = commandsMap.at(tokens[index]);
      index += command->execute(tokens, index);
    }
  }
}

/**
 * Generates the predefined commands map.
 */
void flightSim::generateMap() {
  this->commandsMap["openDataServer"] = new OpenServer(this->varManager, this->expressionInterpreter);
  this->commandsMap["connectControlClient"] = this->client;
  this->commandsMap["var"] = new DefineVar(this->varManager, &this->commandsMap,this->changeCommand);
  this->commandsMap["Sleep"] = new Sleep(this->expressionInterpreter);
  this->commandsMap["Print"] = new Print();
}

/**
 * Constructs the flightSim object, creates the various command objects we'll use.
 * @param name the name of the file we'll lex and then parse.
 */
flightSim::flightSim(std::string name) {
  this->fileName = std::move(name);
  this->varManager = new VariableManager();
  this->expressionInterpreter = new Interpreter(this->varManager);
  this->client = new OpenClient(this->expressionInterpreter);
  this->changeCommand = new ChangeVar(this->varManager,this->expressionInterpreter,this->client);
}
