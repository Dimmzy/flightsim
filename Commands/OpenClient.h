
#ifndef FLIGHTSIM_COMMANDS_OPENCLIENT_H_
#define FLIGHTSIM_COMMANDS_OPENCLIENT_H_
#include "../Command.h"

class OpenClient : public Command {
 public:
  int execute(std::vector<std::string> args);
 private:
  static void startClient(const char* ip, int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENCLIENT_H_
