
#include "Print.h"

int Print::execute(std::vector<std::string> args) {
  std::cout << args[1] << std::endl;
  return 3;
}