#ifndef FLIGHTSIM_COMMANDS_WHILELOOP_H_
#define FLIGHTSIM_COMMANDS_WHILELOOP_H_
#include "../Command.h"
#include "ConditionParser.h"

class WhileLoop : public ConditionParser {
 public:
  int execute(std::vector<std::string> lexVector, int index);
};

#endif //FLIGHTSIM_COMMANDS_WHILELOOP_H_
