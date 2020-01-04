#include "WhileLoop.h"
#define ARG_OFFSET 1


int WhileLoop::execute(std::vector<std::string> lexVector, int index) {
  int indexTemp = index;
  // while the condition is true
  while(booleanOperator(lexVector[indexTemp + 1])) {
    index = indexTemp;
    index = index + 3;
    // while we have not finished excuting all the commands inside the loop
    while (lexVector[index] != "}") {
      //execute the inner commands
      if (commandsMap->find(lexVector[index]) != commandsMap->end()) {
        Command *command = commandsMap->at(lexVector[index]);
        index += command->execute(lexVector, index);
      }
    }
  }
  return index - indexTemp + 1;
}
WhileLoop::WhileLoop(std::map<std::string, Command *>* commandsMap, VariableManager* varManager, Interpreter*
interpreter1)
:ConditionParser(varManager, commandsMap, interpreter1) { }