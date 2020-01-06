#ifndef FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#define FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#include "../Command.h"
#include "../Expression/Interpreter.h"

class ConditionParser : public Command {
 protected:
  std::map<std::string, Command*>* commandsMap;
  Interpreter* interpreter;
  VariableManager* varManager;


 public:
  int execute(std::vector<std::string> lexVector, int index);
  bool booleanOperator(std::string& booleanString);
  size_t indexOfBeginningOfCondition(const std::string charArray[], const std::string& str, int* count);
  ConditionParser(VariableManager* varM, std::map<std::string, Command*>* commandsM, Interpreter* interpret);
  bool checkTrueOrFalse(const std::string& exp1, const std::string& ex2, const std::string& condition);
};


#endif //FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
