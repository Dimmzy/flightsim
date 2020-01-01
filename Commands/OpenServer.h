
#ifndef FLIGHTSIM_COMMANDS_OPENSERVER_H_
#define FLIGHTSIM_COMMANDS_OPENSERVER_H_
#include <mutex>
#include <condition_variable>
#include "../Command.h"
#include "../VariableManager.h"
#include "../Expression/Expression.h"
#include "../Expression/Interpreter.h"

class OpenServer : public Command {
 public:
  explicit OpenServer(VariableManager* varman, Interpreter* interp,condition_variable* con_v,mutex* mutex)
  : vm(varman),interpreter(interp),cv(con_v),mx(mutex) {};
  int execute(std::vector<std::string> lexVector, int index) override;
 private:
  condition_variable* cv;
  mutex* mx;
  Interpreter* interpreter;
  VariableManager* vm;
  void startServer(int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENSERVER_H_
