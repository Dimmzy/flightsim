#include "ConditionParser.h"
#include "string.h"

#include "../Expression/Interpreter.h"
int ConditionParser::execute(std::vector<std::string> lexVector, int index) {
  return 0;
}

ConditionParser::ConditionParser(VariableManager* varManager, std::vector<Command*> cmdVector) {
  this->varManager = varManager;
  this->cmdVector = cmdVector;
}

size_t ConditionParser::indexOfBeginningOfCondition(const std::string charArray[], const std::string& str, int*
count) {
  size_t pos = std::string::npos;
  for(unsigned i = 0; i < str.size(); i++) {
    pos = str.find(charArray[i]);
    if(pos != std::string::npos) {
      (*count)++;
      if(charArray->find(str[pos + 1]) != std::string::npos)
        (*count)++;
      return pos;
    }
  }
  return pos;
}

bool ConditionParser::booleanOperator(std::string& booleanString) {
  int count = 0;
  const std::string charArray[] = {"<=", ">=", "<", ">", "==", "!="};
  std::string conditionCharacter;
  size_t pos = indexOfBeginningOfCondition(charArray, booleanString, &count);
  std::string expression1 = booleanString.substr(0, pos - 1), expression2;
  expression2 = booleanString.substr(pos + count, booleanString.size() - 1);
  if(count == 1)
    conditionCharacter = booleanString[pos];
  if(count == 2)
    conditionCharacter = booleanString.substr(pos, pos + 1);
  return checkTrueOrFalse(expression1, expression2, conditionCharacter);
}

bool ConditionParser::checkTrueOrFalse(std::string& exp1, std::string& exp2, std::string& condition) {
  double val1, val2;
  Interpreter i;
  Expression *leftExpression = i.interpret(exp1), *rightExpression = i.interpret(exp2);
  //check if the expression before the condition character(<,== ...) is a variable
  if(varManager->getSymbolTable().find(exp1) != (varManager->getSymbolTable().end())) {
    val1 = varManager->getSymbolTable().at(exp1)->getValue();
  } else {
    val1 = std::stod(exp1);
  }

  //check if the expression after the condition character(<,== ...) is a variable
  if(varManager->getSymbolTable().find(exp2) != (varManager->getSymbolTable().end())) {
    val2 = varManager->getSymbolTable().at(exp2)->getValue();
  } else {
    val2 = std::stod(exp2);
  }

  if(condition.compare("<=") == 0) {
    return val1 <= val2;
  }
  if(condition.compare("<") == 0) {
    return val1 < val2;
  }
  if(condition.compare(">=") == 0) {
    return val1 >= val2;
  }
  if(condition.compare("==") == 0) {
    return val1 == val2;
  }
  if(condition.compare(">") == 0) {
    return val1 > val2;
  }
}
