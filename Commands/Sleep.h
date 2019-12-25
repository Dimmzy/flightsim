#ifndef FLIGHTSIM_COMMANDS_SLEEP_H_
#define FLIGHTSIM_COMMANDS_SLEEP_H_
#include "../Command.h"

class Sleep : public Command {
 public:
  int execute(std::vector<std::string> args);
};

#endif //FLIGHTSIM_COMMANDS_SLEEP_H_
