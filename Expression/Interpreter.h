

#ifndef EX1__INTERPRETER_H_
#define EX1__INTERPRETER_H_

#include <string>
#include <map>
#include <vector>
#include <queue>
#include "Expression.h"

class Interpreter {
 private:
  static bool isOperator(const string &s);
  static int precedence(const string &s);
  map<string, string> varMap;
  static vector<string> tokenize(const string &str, const char delimiter);
 public:
  void setVariables(const string &vars);
  Expression *interpret(const string &str);
  Interpreter() = default;
  ~Interpreter() = default;
  queue<string> ShuntingYard(string str);
};

#endif //EX1__INTERPRETER_H_
