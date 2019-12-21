
#ifndef FLIGHTSIM__CSVPARSER_H_
#define FLIGHTSIM__CSVPARSER_H_
#include <map>
#include "Command.h"

class CSVParser {
  static map<std::string,Command> parseFile(std::string csv);
};

#endif //FLIGHTSIM__CSVPARSER_H_
