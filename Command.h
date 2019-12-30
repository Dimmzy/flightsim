#ifndef FLIGHTSIM__COMMAND_H_
#define FLIGHTSIM__COMMAND_H_

#include <vector>
#include <thread>
#include <chrono>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include "VariableManager.h"
#include "Variable.h"


class Command {
 public:
  Command()= default;
  virtual ~Command()= default;
  virtual int execute(std::vector<std::string> lexVector, int index) = 0;
};



#endif //FLIGHTSIM__COMMAND_H_