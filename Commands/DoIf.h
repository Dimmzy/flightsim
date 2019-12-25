#ifndef FLIGHTSIM_COMMANDS_DOIF_H_
#define FLIGHTSIM_COMMANDS_DOIF_H_
#include "../Command.h"

class DoIf : public Command {
 public:
  int execute(std::vector<std::string> args);
};

#endif //FLIGHTSIM_COMMANDS_DOIF_H_
