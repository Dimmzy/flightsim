#include "ChangeVar.h"
#define EXP_OFFSET 3
#define END_OFFSET 3

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
