
#ifndef FLIGHTSIM_COMMANDS_OPENSERVER_H_
#define FLIGHTSIM_COMMANDS_OPENSERVER_H_
#include "../Command.h"

class OpenServer : public Command {
 public:
  int execute(std::vector<std::string> args);
 private:
  static void startServer(int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENSERVER_H_
