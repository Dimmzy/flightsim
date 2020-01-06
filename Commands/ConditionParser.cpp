#include "ConditionParser.h"
#include <cstring>
#include "../Expression/Interpreter.h"


int ConditionParser::execute(std::vector<std::string> lexVector, int index) {
  return 0;
}

ConditionParser::ConditionParser(VariableManager* varM, std::map<std::string, Command*>* commandsM,
                                 Interpreter* interpret) {
  this->varManager = varM;
  this->commandsMap = commandsM;
  this->interpreter = interpret;
}

size_t ConditionParser::indexOfBeginningOfCondition(const std::string charArray[], const std::string& str, int*
count) {
  size_t pos = std::string::npos;
  for(unsigned i = 0; i < str.size(); i++) {
    pos = str.find(charArray[i]);
    if(pos != std::string::npos) {
      (*count)++;
      if(charArray->find(str[pos + 1]) != std::string::npos)
        (*count)++; //if the condition character has two characters (e.g <=)
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
  //take the string before the condition character
  std::string expression1 = booleanString.substr(0, pos), expression2;
  //take the string after the condition character
  expression2 = booleanString.substr(pos + count, booleanString.size() - 1);
  conditionCharacter = booleanString.substr(pos, count);
  return checkTrueOrFalse(expression1, expression2, conditionCharacter);
}

bool ConditionParser::checkTrueOrFalse(const std::string& exp1,const std::string& exp2,const std::string& condition) {
  double val1, val2;
  Expression* e1 = this->interpreter->interpret(exp1);
  Expression* e2 = this->interpreter->interpret(exp2);
  val1 = e1->calculate();
  val2 = e2->calculate();
  if (condition == "<=") {
    return val1 <= val2;
  }
  if (condition == "<") {
    return val1 < val2;
  }
  if (condition == ">=") {
    return val1 >= val2;
  }
  if (condition == "==") {
    return val1 == val2;
  }
  if (condition == ">") {
    return val1 > val2;
  }
  if (condition == "!=") {
    return val1 != val2;
  }
}
