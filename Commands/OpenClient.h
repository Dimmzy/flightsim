#ifndef FLIGHTSIM_COMMANDS_OPENCLIENT_H_
#define FLIGHTSIM_COMMANDS_OPENCLIENT_H_
#include "../Command.h"
#include "../Expression/Interpreter.h"

class OpenClient : public Command {
 public:
  OpenClient(Interpreter* interp) : interpreter(interp) {};
  int execute(std::vector<std::string> lexVector, int index);
  void sendUpdate(const std::string& message);
 private:
  Interpreter* interpreter;
  int  clientSocket;
  void startClient(const char* ip, int port);
};

#endif //FLIGHTSIM_COMMANDS_OPENCLIENT_H_
