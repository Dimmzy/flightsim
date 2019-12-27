#ifndef FLIGHTSIM_COMMANDS_DEFINEVAR_H_
#define FLIGHTSIM_COMMANDS_DEFINEVAR_H_
#include "../Command.h"

class DefineVar : public Command {
 private:
  VariableManager varManager;
 public:
  DefineVar(VariableManager vm) : varManager(vm) {};
  int execute(std::vector<std::string> args);
};

#endif //FLIGHTSIM_COMMANDS_DEFINEVAR_H_
