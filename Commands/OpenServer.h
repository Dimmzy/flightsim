
#ifndef FLIGHTSIM_COMMANDS_OPENSERVER_H_
#define FLIGHTSIM_COMMANDS_OPENSERVER_H_
#include "../Command.h"
#include "../VariableManager.h"
#include "../Expression/Expression.h"
#include "../Expression/Interpreter.h"

class OpenServer : public Command {
 public:
  explicit OpenServer(VariableManager* varman, Interpreter* interp) : vm(varman),interpreter(interp) {};
  int execute(std::vector<std::string> lexVector, int index) override;
 private:
  Interpreter* interpreter;
  VariableManager* vm;
  void startServer(int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENSERVER_H_
