#ifndef FLIGHTSIM_COMMANDS_SLEEP_H_
#define FLIGHTSIM_COMMANDS_SLEEP_H_
#include "../Command.h"
#include "../Expression/Interpreter.h"
#include "../Expression/Expression.h"
#include <math.h>

class Sleep : public Command {
 private:
  Interpreter* interpreter;
 public:
  explicit Sleep (Interpreter* interp): interpreter(interp) {};
  int execute(std::vector<std::string> lexVector, int index);
};

#endif //FLIGHTSIM_COMMANDS_SLEEP_H_
