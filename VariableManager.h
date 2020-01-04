#ifndef FLIGHTSIM__VARIABLEMANAGER_H_
#define FLIGHTSIM__VARIABLEMANAGER_H_

#include <map>
#include <vector>
#include "Variable.h"

/**
 * VariableManager handles the maps of our Variables.
 * The SymbolTable which handles mapping from a variable name to the Variable object [Client -> Simulator]
 * The BoundTable which handles mapping from a sim name to the Variable object [Simulator -> Server]
 */
class VariableManager {
  std::map<std::string, Variable*> symbolTable; // Variable Name to Variable Object
  std::map<std::string, Variable*> boundTable; // Sim Variable Name to Variable Object (update from sim)
 public:
  std::vector<std::string> XMLVars;
  VariableManager();
  void addSymbol(std::string str, Variable* var);
  void addBoundTable(std::string str, Variable* var);
  std::map<std::string, Variable*> getSymbolTable();
  std::map<std::string, Variable*> getBoundTable();
  std::string getVarPath(int i);
};

#endif //FLIGHTSIM__VARIABLEMANAGER_H_
