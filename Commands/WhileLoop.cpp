#include "WhileLoop.h"
#define ARG_OFFSET 1


int WhileLoop::execute(std::vector<std::string> lexVector, int index) {
  while(booleanOperator(lexVector[index + ARG_OFFSET])) {
    index = index + 3;
    while (lexVector[index] != "}") {
      if (commandsMap.find(lexVector[index]) != commandsMap.end()) {
        Command *command = commandsMap.at(lexVector[index]);
        index += command->execute(lexVector, index);
      }
    }
    return index;
  }
  return 0;
}
WhileLoop::WhileLoop(std::map<std::string, Command *>& commandsMap, VariableManager *varManager):ConditionParser
(varManager, commandsMap) { }

