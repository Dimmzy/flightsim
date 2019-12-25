
#ifndef FLIGHTSIM__VARIABLEMANAGER_H_
#define FLIGHTSIM__VARIABLEMANAGER_H_
#include <map>
#include "Variable.h"

class VariableManager {
  std::map<std::string, Variable*> symbolTable;
  std::map<std::string, Variable*> boundTable;

 public:
  void addSymbol(std::string str, Variable* var);
  void addBoundTable(std::string str, Variable* var);
};

#endif //FLIGHTSIM__VARIABLEMANAGER_H_
