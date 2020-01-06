
#ifndef FLIGHTSIM__VARIABLE_H_
#define FLIGHTSIM__VARIABLE_H_
#include <string>

/**
 * The Variable class handles our programs flight variables that are kept in their corresponding maps.
 */
class Variable {
  double value;
  std::string simPath;

 public:
  Variable(double val, const std::string &sim_path);
  double getValue();
  std::string getPath();
  void setValue(double val);
};

#endif //FLIGHTSIM__VARIABLE_H_
