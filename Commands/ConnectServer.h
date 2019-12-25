
#ifndef FLIGHTSIM_COMMANDS_CONNECTSERVER_H_
#define FLIGHTSIM_COMMANDS_CONNECTSERVER_H_
#include "../Command.h"

class ConnectServer : public Command {
 public:
  int execute(std::vector<std::string> args);
 private:
  static void startClient(const char* ip, int port);
};

#endif //FLIGHTSIM_COMMANDS_CONNECTSERVER_H_
