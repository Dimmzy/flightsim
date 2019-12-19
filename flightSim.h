#ifndef FLIGHTSIM__FLIGHTSIM_H_
#define FLIGHTSIM__FLIGHTSIM_H_
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "variable.h"
#include "command.h"
#include "lexer.h"

using namespace std;

class flightSim {
  map<string, variable> varMap;
  map<string, variable> pathMap;
  //map<string, command> cmdMap;

 public:
  void run();
};

#endif //FLIGHTSIM__FLIGHTSIM_H_
