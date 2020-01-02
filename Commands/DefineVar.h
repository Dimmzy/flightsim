#ifndef FLIGHTSIM_COMMANDS_DEFINEVAR_H_
#define FLIGHTSIM_COMMANDS_DEFINEVAR_H_
#include "../Command.h"
#include "ChangeVar.h"

class DefineVar : public Command {
 private:
  std::map<std::string, Command*>* commandsMap;
  ChangeVar* changeVarCommand;
  VariableManager* varManager;
 public:
  explicit DefineVar(VariableManager* vm,std::map<std::string, Command*>*  cMap, ChangeVar* change) : varManager(vm),
  commandsMap(cMap), changeVarCommand(change) {};
  int execute(std::vector<std::string> lexVector, int index) override;
};

#endif //FLIGHTSIM_COMMANDS_DEFINEVAR_H_
