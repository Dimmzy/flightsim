#include "Sleep.h"
#define ARG_OFFSET 2
#define END_OFFSET 4

/**
 * Puts the thread to sleep for the given duration.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int Sleep::execute(std::vector<std::string> lexVector, int index) {
  Expression* exp = this->interpreter->interpret(lexVector[index + ARG_OFFSET]);
  std::this_thread::sleep_for(std::chrono::milliseconds(int((exp->calculate()))));
  return END_OFFSET;
}