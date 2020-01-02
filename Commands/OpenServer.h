#ifndef FLIGHTSIM_COMMANDS_OPENSERVER_H_
#define FLIGHTSIM_COMMANDS_OPENSERVER_H_

#include <mutex>
#include <condition_variable>
#include "../Command.h"
#include "../VariableManager.h"
#include "../Expression/Expression.h"
#include "../Expression/Interpreter.h"

/**
 * OpenServer class handles opening a server the simulator connects to and to which it sends updates on the parameters
 * defined in the parsed text.
 */
class OpenServer : public Command {
 public:
  explicit OpenServer(VariableManager* varman, Interpreter* interp) : vm(varman),interpreter(interp) {}
  int execute(std::vector<std::string> lexVector, int index) override;
 private:
  Interpreter* interpreter;
  VariableManager* vm;
  void startServer(int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENSERVER_H_
