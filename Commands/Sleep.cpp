#include "Sleep.h"
#define ARG_OFFSET 2
#define END_OFFSET 4

int Sleep::execute(std::vector<std::string> lexVector, int index) {
  Expression* exp = this->interpreter->interpret(lexVector[index + ARG_OFFSET]);
  std::this_thread::sleep_for(std::chrono::milliseconds(int((exp->calculate()))));
  return END_OFFSET;
}