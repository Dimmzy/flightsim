#include "Sleep.h"

int Sleep::execute(std::vector<std::string> args) {
  std::this_thread::sleep_for(std::chrono::milliseconds(stoi(args[0])));
  return 2;
}