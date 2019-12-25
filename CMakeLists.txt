cmake_minimum_required(VERSION 3.15)
project(flightsim)

set(CMAKE_CXX_STANDARD 14)

add_executable(flightsim main.cpp flightSim.cpp flightSim.h Command.h lexer.cpp
        lexer.h CSVParser.cpp CSVParser.h Command.cpp VariableManager.cpp VariableManager.h Variable.cpp Variable.h)