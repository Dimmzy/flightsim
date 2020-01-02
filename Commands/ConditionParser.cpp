#include "ConditionParser.h"
#include "string.h"

#include "../Expression/Interpreter.h"
int ConditionParser::execute(std::vector<std::string> lexVector, int index) {
  return 0;
}

ConditionParser::ConditionParser(VariableManager* varManager, std::map<std::string, Command*>& commandsMap) {
  this->varManager = varManager;
  this->commandsMap = commandsMap;
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
  std::string expression1 = booleanString.substr(0, pos), expression2;
  expression2 = booleanString.substr(pos + count, booleanString.size() - 1);
  conditionCharacter = booleanString.substr(pos, count);
  return checkTrueOrFalse(expression1, expression2, conditionCharacter);
}

bool ConditionParser::checkTrueOrFalse(const std::string& exp1,const std::string& exp2,const std::string& condition) {
  double val1, val2;
  auto itEnd1 = varManager->getSymbolTable().end(),
       itEnd2 = varManager->getBoundTable().end(),
       itFindSymbolExp1 = varManager->getSymbolTable().find(exp1),
       itFindSymbolExp2 = varManager->getSymbolTable().find(exp2),
       itFindBoundExp1 = varManager->getBoundTable().find(exp1),
       itFindBoundExp2 = varManager->getBoundTable().find(exp2);

  //check if the expression before the condition character(<,== ...) is a variable
  if(itFindSymbolExp1 != itEnd1) {
    val1 = varManager->getSymbolTable().at(exp1)->getValue();
  } else {
    if(itFindBoundExp1 != itEnd2) {
      val1 = varManager->getBoundTable().at(exp1)->getValue();
    } else {
      val1 = std::stod(exp1);
    }
  }

  //check if the expression after the condition character(<,== ...) is a variable
  if(itFindSymbolExp2 != itEnd1) {
    val2 = varManager->getSymbolTable().at(exp2)->getValue();
  } else {
    if (itFindBoundExp2 != itEnd2) {
      val2 = varManager->getBoundTable().at(exp2)->getValue();
    } else {
      val2 = std::stod(exp2);
    }
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
  if(condition.compare("!=") == 0) {
    return val1 != val2;
  }
}
