#ifndef FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#define FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#include "../Command.h"

class ConditionParser : public Command {
 private:
  std::vector<Command*> cmdVector;
  VariableManager* varManager;
 public:
  int execute(std::vector<std::string> lexVector, int index);
  bool booleanOperator(std::string& booleanString);
  size_t indexOfBeginningOfCondition(const std::string charArray[], const std::string& str, int* count);
  ConditionParser(VariableManager* varManager, std::vector<Command*> cmdVector);
  bool checkTrueOrFalse(std::string& exp1, std::string& ex2, std::string& condition);

};


#endif //FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
