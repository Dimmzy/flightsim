
#include "Print.h"
#define ARG_OFFSET 2
#define END_OFFSET 4

int Print::execute(std::vector<std::string> lexVector, int index) {
  std::cout << lexVector[index + ARG_OFFSET] << std::endl;
  return END_OFFSET;
}