#include "DefineVar.h"


int DefineVar::execute(std::vector<std::string> args) {
  int index = 1;
  std::string varName = args[index];
  std::string varPath = args[index + 5];
  index++;
  auto* newVar = new Variable(0,varPath);
  if (args[index] == "<") {
    this->varManager->addBoundTable(varPath,newVar);
    this->varManager->addSymbol(varName,newVar);
  } else if (args[index] == "-")  {
    this->varManager->addSymbol(varName,newVar);
  }
  return 8;
}