#ifndef FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#define FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
#include "../Command.h"

class ConditionParser : public Command {
 private:
  VariableManager* varManager;
 protected:
  std::map<std::string, Command*>* commandsMap;


 public:
  int execute(std::vector<std::string> lexVector, int index);
  bool booleanOperator(std::string& booleanString);
  size_t indexOfBeginningOfCondition(const std::string charArray[], const std::string& str, int* count);
  ConditionParser(VariableManager* varManager, std::map<std::string, Command*>* commandsMap);
  bool checkTrueOrFalse(const std::string& exp1, const std::string& ex2, const std::string& condition);
};


#endif //FLIGHTSIM_COMMANDS_CONDITIONPARSER_H_
