#ifndef FLIGHTSIM_COMMANDS_PRINT_H_
#define FLIGHTSIM_COMMANDS_PRINT_H_
#include "../Command.h"

class Print : public Command {
 public:
  int execute(std::vector<std::string> args);
};

#endif //FLIGHTSIM_COMMANDS_PRINT_H_
