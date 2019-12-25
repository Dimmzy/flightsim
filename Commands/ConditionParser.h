#ifndef FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#define FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#include "../Command.h"

class ConditionParser : public Command {
 private:
  std::vector<Command*> cmdVector;
 public:
  int execute(std::vector<std::string> args);
};


#endif //FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
