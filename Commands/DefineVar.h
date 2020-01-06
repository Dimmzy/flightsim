#ifndef FLIGHTSIM_COMMANDS_DEFINEVAR_H_
#define FLIGHTSIM_COMMANDS_DEFINEVAR_H_

#include "../Command.h"
#include "ChangeVar.h"

/**
 * DefineVar class handles defining and adding new variables to our maps and whether we get them through the server
 * or the client. We update both boundMap and symbolTable if it's a variable we get from the simulator, and only
 * symbolTable if it's a variable we manually update.
 */
class DefineVar : public Command {
 private:
  VariableManager* varManager;
  std::map<std::string, Command*>* commandsMap;
  ChangeVar* changeVarCommand;
 public:
  explicit DefineVar(VariableManager* vm,std::map<std::string, Command*>*  cMap, ChangeVar* change) : varManager(vm),
  commandsMap(cMap), changeVarCommand(change) {};
  int execute(std::vector<std::string> lexVector, int index) override;
};

#endif //FLIGHTSIM_COMMANDS_DEFINEVAR_H_
