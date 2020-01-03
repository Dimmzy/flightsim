#include "Print.h"
#define ARG_OFFSET 2
#define END_OFFSET 4

/**
 * Simply prints the string we're provided.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int Print::execute(std::vector<std::string> lexVector, int index) {
  if (lexVector[index + ARG_OFFSET][0] == '\"') {
    std::string s = lexVector[index + ARG_OFFSET];
    s.erase (remove(s.begin(),s.end(),'\"'), s.end());
    std::cout << s << std::endl;
  }
  else {
    Expression* exp = interpreter->interpret(lexVector[index + ARG_OFFSET]);
    std::cout << exp->calculate() << std::endl;
  }
  return END_OFFSET;
}