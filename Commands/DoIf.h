#ifndef FLIGHTSIM_COMMANDS_DOIF_H_
#define FLIGHTSIM_COMMANDS_DOIF_H_
#include "../Command.h"
#include "ConditionParser.h"

class DoIf : public ConditionParser {
 public:
  int execute(std::vector<std::string> lexVector, int index);
  DoIf(std::map<std::string, Command*>* commandsMap, VariableManager* varManager);
};

#endif //FLIGHTSIM_COMMANDS_DOIF_H_
