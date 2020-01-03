#include "DefineVar.h"
#define NAME_OFFSET 1
#define PATH_OFFSET 5
#define OP_OFFSET 2
#define DEFINED_OFFSET_PATH 3
#define END_OFFSET 7

/**
 * We extract the variable information, insert it to our commandsMap and the corresponding maps to it's type.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int DefineVar::execute(std::vector<std::string> lexVector, int index) {
  // Extracts name and path through offsets
  std::string varName = lexVector[index + NAME_OFFSET];
  // Adds the variable to the commands map so we can execute a value change through it.
  this->commandsMap->insert(std::pair<std::string,Command*>(varName,this->changeVarCommand));
  if (lexVector[index + OP_OFFSET] == "<-") { // Bound variable
    std::string varPath = lexVector[index + PATH_OFFSET];
    auto* newVar = new Variable(0,varPath); // Initialize value to zero
    std::cout << "Added Bound Variable: " + varName << std::endl;
    std::cout << "At path: " + varPath << std::endl;
    this->varManager->addBoundTable(varPath,newVar);
    this->varManager->addSymbol(varName,newVar);
  } else if (lexVector[index + OP_OFFSET] == "->")  { // Regular variable
    std::string varPath = lexVector[index + PATH_OFFSET];
    auto* newVar = new Variable(0,varPath);
    std::cout << "Added Regular Variable: " + varName << std::endl;
    this->varManager->addSymbol(varName,newVar);
  } else { // new Variable using already defined variable's value
    std::map<std::string, Variable*> symTable = this->varManager->getSymbolTable();
    std::string varPath = symTable.at(lexVector[index + DEFINED_OFFSET_PATH])->getPath();
    auto* newVar = new Variable(symTable.at(lexVector[index + DEFINED_OFFSET_PATH])->getValue(), varPath);
    this->varManager->addSymbol(varName,newVar);
  }
  return END_OFFSET;
}