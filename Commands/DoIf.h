#ifndef FLIGHTSIM_COMMANDS_DOIF_H_
#define FLIGHTSIM_COMMANDS_DOIF_H_
#include "../Command.h"

class DoIf : public Command {
 public:
  int execute(std::vector<std::string> lexVector, int index);
};

#endif //FLIGHTSIM_COMMANDS_DOIF_H_
