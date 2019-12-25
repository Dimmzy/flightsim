
#include "VariableManager.h"

void VariableManager::addSymbol(std::string str, Variable *var) {
  this->symbolTable.insert(std::pair<std::string,Variable*>(str,var));
}
void VariableManager::addBoundTable(std::string str, Variable *var) {
  this->boundTable.insert(std::pair<std::string,Variable*>(str,var));
}
std::map<std::string, Variable *> VariableManager::getSymbolTable() {
  return this->symbolTable;
}
std::map<std::string, Variable *> VariableManager::getBoundTable() {
  return this->boundTable;
}

