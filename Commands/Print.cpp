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
  std::cout << lexVector[index + ARG_OFFSET] << std::endl;
  return END_OFFSET;
}