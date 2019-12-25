#ifndef FLIGHTSIM__COMMAND_H_
#define FLIGHTSIM__COMMAND_H_
#include "flightSim.h"
#include <vector>
#include <thread>
#include <chrono>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <VariableManager.h>
#include <Variable.h>


class Command {
 public:
  Command()= default;
  virtual ~Command()= default;
  virtual int execute(std::vector<std::string> args) = 0;
};

class OpenServer : public Command {
 public:
  int execute(std::vector<std::string> args);
 private:
  static void startServer(int port);
};

class ConnectServer : public Command {
 public:
  int execute(std::vector<std::string> args);
 private:
  static void startClient(const char* ip, int port);
};

class Print : public Command {
 public:
  int execute(std::vector<std::string> args);
};

class Sleep : public Command {
 public:
  int execute(std::vector<std::string> args);
};

class DefineVar : public Command {
 private:
  VariableManager* varManager;
 public:
  DefineVar(VariableManager& vm) : varManager(vm) {};
  int execute(std::vector<std::string> args);
};

class ConditionParser : public Command {
 private:
  std::vector<Command* loopcmd> cmdVector;
 public:
  int execute(std::vector<std::string> args);
};

class WhileLoop : public Command {
 public:
  int execute(std::vector<std::string> args);
};

class IfCommand : public Command {
 public:
  int execute(std::vector<std::string> args);
};

#endif //FLIGHTSIM__COMMAND_H_