#ifndef FLIGHTSIM_COMMANDS_OPENCLIENT_H_
#define FLIGHTSIM_COMMANDS_OPENCLIENT_H_

#include "../Command.h"
#include "../Expression/Interpreter.h"

/**
 * OpenClient class handles opening a socket through which we connect as a client to the simulator and send updates.
 */
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
