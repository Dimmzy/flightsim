cmake_minimum_required(VERSION 3.15)
project(flightsim)

set(CMAKE_CXX_STANDARD 14)

add_executable(flightsim main.cpp flightSim.cpp flightSim.h Command.h lexer.cpp
        lexer.h CSVParser.cpp CSVParser.h VariableManager.cpp VariableManager.h Variable.cpp Variable.h Commands/OpenServer.cpp Commands/OpenServer.h Commands/ConnectServer.cpp Commands/ConnectServer.h Commands/Print.cpp Commands/Print.h Commands/Sleep.cpp Commands/Sleep.h Commands/DefineVar.cpp Commands/DefineVar.h Commands/ConditionParser.cpp Commands/ConditionParser.h Commands/WhileLoop.cpp Commands/WhileLoop.h Commands/DoIf.cpp Commands/DoIf.h)