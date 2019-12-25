
#ifndef FLIGHTSIM__VARIABLEMANAGER_H_
#define FLIGHTSIM__VARIABLEMANAGER_H_
#include <map>
#include "Variable.h"

class VariableManager {
  std::map<std::string, Variable*> symbolTable; // Variable Name to Variable Object
  std::map<std::string, Variable*> boundTable; // Variable Name to Variable Object (update from sim)

 public:
  void addSymbol(std::string str, Variable* var);
  void addBoundTable(std::string str, Variable* var);
  std::map<std::string, Variable*> getSymbolTable();
  std::map<std::string, Variable*> getBoundTable();
};

#endif //FLIGHTSIM__VARIABLEMANAGER_H_
