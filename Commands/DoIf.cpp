#include "DoIf.h"

#define ARG_OFFSET 1

int DoIf::execute(std::vector<std::string> lexVector, int index) {
  int indexTemp = index;
  if(booleanOperator(lexVector[indexTemp + 1])) {
    index = indexTemp;
    index = index + 3;
    while (lexVector[index] != "}") {
      if (commandsMap->find(lexVector[index]) != commandsMap->end()) {
        Command *command = commandsMap->at(lexVector[index]);
        index += command->execute(lexVector, index);
      }
    }
  }
  return index - indexTemp + 1;
}
DoIf::DoIf(std::map<std::string, Command *>* commandsMap, VariableManager *varManager):
ConditionParser(varManager, commandsMap) {

}
