#include <iostream>
#include "flightSim.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Parsing file not provided, exiting..." << std::endl;
    return -1;
  }
  auto* sim = new flightSim(argv[1]);
  sim->run();
  return 0;
}
