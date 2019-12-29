
#ifndef FLIGHTSIM_COMMANDS_OPENSERVER_H_
#define FLIGHTSIM_COMMANDS_OPENSERVER_H_
#include "../Command.h"
#include "../VariableManager.h"

class OpenServer : public Command {
 public:
  explicit OpenServer(VariableManager* varm) : vm(varm) {};
  int execute(std::vector<std::string> args) override;
 private:
  VariableManager* vm;
  void startServer(int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENSERVER_H_
