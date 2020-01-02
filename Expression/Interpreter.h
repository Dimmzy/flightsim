#ifndef EX1__INTERPRETER_H_
#define EX1__INTERPRETER_H_

#include <string>
#include <map>
#include <vector>
#include <queue>
#include "Expression.h"
#include "../VariableManager.h"

/**
 * The interpreter class allows us to interpret a string and convert it into an Expression we can then calculate.
 */
class Interpreter {
 private:
  VariableManager* varManager;
  static bool isOperator(const string &s);
  static int precedence(const string &s);
 public:
  Expression *interpret(const string &str);
  explicit Interpreter(VariableManager *var_manager);
  ~Interpreter() = default;
  static queue<string> ShuntingYard(string str);
};

#endif //EX1__INTERPRETER_H_
