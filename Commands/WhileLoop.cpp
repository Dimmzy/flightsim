#include "WhileLoop.h"
#define ARG_OFFSET 1

/**
 * executes the while loop. Iterate the commands and executes each.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
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
/**
 * Constructor.
 * @param commandsM
 * @param varM
 * @param interpret
 */
WhileLoop::WhileLoop(std::map<std::string, Command *>* commandsM, VariableManager* varM, Interpreter*
interpret)
:ConditionParser(varM, commandsM, interpret) { }