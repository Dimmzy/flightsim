#include "DefineVar.h"
#define NAME_OFFSET 1
#define PATH_OFFSET 5
#define OP_OFFSET 2
#define END_OFFSET 7

int DefineVar::execute(std::vector<std::string> lexVector, int index) {
  std::string varName = lexVector[index + NAME_OFFSET];
  std::string varPath = lexVector[index + PATH_OFFSET];
  this->commandsMap->insert(std::pair<std::string,Command*>(varName,this->changeVarCommand));
  auto* newVar = new Variable(0,varPath); // Initialize value to zero
  if (lexVector[index + OP_OFFSET] == "<-") { // Bound variable
    std::cout << "Added Bound Variable: " + varName << std::endl;
    std::cout << "At path: " + varPath << std::endl;
    this->varManager->addBoundTable(varPath,newVar);
    this->varManager->addSymbol(varName,newVar);
  } else  { // Regular variable
    std::cout << "Added Regular Variable: " + varName << std::endl;
    this->varManager->addSymbol(varName,newVar);
  }
  return END_OFFSET;
}