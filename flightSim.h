#ifndef FLIGHTSIM__FLIGHTSIM_H_
#define FLIGHTSIM__FLIGHTSIM_H_
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "variable.h"
#include "Command.h"
#include "lexer.h"
#include "Commands/Connect.h"
#include "Commands/DefineVar.h"
#include "Commands/OpenServer.h"
#include "Commands/Print.h"
#include "Commands/Sleep.h"


class flightSim {
  std::string fileName;
  map<std::string, Command> commands;

 public:
  flightSim(std::string name) : fileName(name) {};
  void run();
 private:
  void generateMap();
};

#endif //FLIGHTSIM__FLIGHTSIM_H_
