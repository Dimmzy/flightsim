#ifndef FLIGHTSIM_COMMANDS_CHANGEVAR_H_
#define FLIGHTSIM_COMMANDS_CHANGEVAR_H_

#include "../VariableManager.h"
#include "../Command.h"
#include "../Commands/OpenClient.h"
#include "../Expression/Expression.h"
#include "../Expression/Interpreter.h"

/**
 * ChangeVar class is a Command type object that handles updating the current variables to new values as parsed.
 */
class ChangeVar : public Command{
 private:
  Interpreter* expressionInterpreter;
  VariableManager* varManager;
  OpenClient* client;
 public:
  int execute(std::vector<std::string> lexVector, int index) override;
  ChangeVar(VariableManager *var_manager, Interpreter* interp, OpenClient* cli) : varManager(var_manager),
  expressionInterpreter(interp), client(cli) {};

};

#endif //FLIGHTSIM_COMMANDS_CHANGEVAR_H_
