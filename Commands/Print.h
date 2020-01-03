#ifndef FLIGHTSIM_COMMANDS_PRINT_H_
#define FLIGHTSIM_COMMANDS_PRINT_H_

#include <algorithm>
#include "../Command.h"
#include "../Expression/Interpreter.h"
#include "../Expression/Expression.h"

/**
 * Print class handles printing to the console.
 */
class Print : public Command {
 private:
  Interpreter* interpreter;
 public:
  explicit Print(Interpreter *interpret) : interpreter(interpret) {}
  int execute(std::vector<std::string> lexVector, int index);
};

#endif //FLIGHTSIM_COMMANDS_PRINT_H_
