
#ifndef FLIGHTSIM__VARIABLE_H_
#define FLIGHTSIM__VARIABLE_H_
#include <string>

class Variable {
  double value;
  std::string simPath;

 public:
  Variable(double value, const std::string &sim_path);
  double getValue();
  std::string getPath();
  void setValue(double val);
  void setPath(std::string path);
};

#endif //FLIGHTSIM__VARIABLE_H_
