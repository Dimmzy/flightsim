#include "ChangeVar.h"
#define EXP_OFFSET 2
#define END_OFFSET 3

/**
 * Calculates the value we change to using the Expression object, updates the symbol table and sends an update to the
 * simulator through the client.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int ChangeVar::execute(std::vector<std::string> lexVector, int index) {
  Expression *exp = expressionInterpreter->interpret(lexVector[index + EXP_OFFSET]);
  map<std::string, Variable*> symTable = this->varManager->getSymbolTable();
  symTable.at(lexVector[index])->setValue(exp->calculate());
  this->client->sendUpdate("set " + symTable.at(lexVector[index])->getPath() + " " +
      to_string(symTable.at(lexVector[index])->getValue()) + "\r\n");
  std::cout << "Var Changed " + lexVector[index] + " " + std::to_string(symTable.at(lexVector[index])->getValue())
            << std::endl;
  return END_OFFSET;
}
