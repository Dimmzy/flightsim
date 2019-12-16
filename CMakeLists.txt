cmake_minimum_required(VERSION 3.15)
project(flightsim)

set(CMAKE_CXX_STANDARD 14)

add_executable(flightsim main.cpp flightSim.cpp flightSim.h variable.h command.h lexer.cpp lexer.h)