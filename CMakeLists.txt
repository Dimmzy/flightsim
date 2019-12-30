cmake_minimum_required(VERSION 3.15)
project(flightsim)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(Expression)

add_executable(flightsim main.cpp flightSim.cpp flightSim.h Command.h lexer.cpp
        lexer.h VariableManager.cpp VariableManager.h Variable.cpp Variable.h Commands/OpenServer.cpp Commands/OpenServer.h Commands/OpenClient.cpp Commands/OpenClient.h Commands/Print.cpp Commands/Print.h Commands/Sleep.cpp Commands/Sleep.h Commands/DefineVar.cpp Commands/DefineVar.h Commands/ConditionParser.cpp Commands/ConditionParser.h Commands/WhileLoop.cpp Commands/WhileLoop.h Commands/DoIf.cpp Commands/DoIf.h)