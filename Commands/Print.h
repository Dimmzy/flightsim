#ifndef FLIGHTSIM_COMMANDS_PRINT_H_
#define FLIGHTSIM_COMMANDS_PRINT_H_

#include "../Command.h"

/**
 * Print class handles printing to the console.
 */
class Print : public Command {
 public:
  int execute(std::vector<std::string> lexVector, int index);
};

#endif //FLIGHTSIM_COMMANDS_PRINT_H_
