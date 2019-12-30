#include "Sleep.h"
#define ARG_OFFSET 1
#define END_OFFSET 4

int Sleep::execute(std::vector<std::string> lexVector, int index) {
  std::this_thread::sleep_for(std::chrono::milliseconds(stoi(lexVector[index + ARG_OFFSET])));
  return END_OFFSET;
}