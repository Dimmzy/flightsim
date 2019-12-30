#ifndef FLIGHTSIM_COMMANDS_WHILELOOP_H_
#define FLIGHTSIM_COMMANDS_WHILELOOP_H_
#include "../Command.h"

class WhileLoop : public Command {
 public:
  int execute(std::vector<std::string> lexVector, int index);
};

#endif //FLIGHTSIM_COMMANDS_WHILELOOP_H_
