cmake_minimum_required(VERSION 3.15)
project(flightsim)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(flightsim main.cpp flightSim.cpp flightSim.h Command.h lexer.cpp
        lexer.h VariableManager.cpp VariableManager.h Variable.cpp Variable.h Commands/OpenServer.cpp Commands/OpenServer.h Commands/OpenClient.cpp Commands/OpenClient.h Commands/Print.cpp Commands/Print.h Commands/Sleep.cpp Commands/Sleep.h Commands/DefineVar.cpp Commands/DefineVar.h Commands/ConditionParser.cpp Commands/ConditionParser.h Commands/WhileLoop.cpp Commands/WhileLoop.h Commands/DoIf.cpp Commands/DoIf.h
        Expression/Interpreter.h Expression/Interpreter.cpp Expression/BinaryOperator.cpp Expression/BinaryOperator.h Expression/Div.cpp Expression/Div.h Expression/Expression.h Expression/ExpressionVariable.cpp Expression/ExpressionVariable.h Expression/Minus.cpp Expression/Minus.h
        Expression/Mul.cpp Expression/Mul.h Expression/Plus.cpp Expression/Plus.h Expression/UMinus.cpp Expression/UMinus.h Expression/UnaryOperator.cpp Expression/UnaryOperator.h Expression/UPlus.cpp Expression/UPlus.h Expression/Value.cpp Expression/Value.h Commands/ChangeVar.cpp Commands/ChangeVar.h)