#include "DoIf.h"

#define ARG_OFFSET 1

/**
 * executes the if condition. Iterate the commands and executes each.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int DoIf::execute(std::vector<std::string> lexVector, int index) {
  int indexTemp = index;
  // check if the condition is true
  if(booleanOperator(lexVector[indexTemp + 1])) {
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
DoIf::DoIf(std::map<std::string, Command *>* commandsM, VariableManager *varM, Interpreter* interpret):
ConditionParser(varM, commandsM, interpret) {}
