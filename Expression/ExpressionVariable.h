
#ifndef EX1__EXPRESSIONVARIABLE_H_
#define EX1__EXPRESSIONVARIABLE_H_
#include <string>
#include "Expression.h"

class ExpressionVariable : public Expression {
 public:
  ExpressionVariable(std::string name, double value);
  ExpressionVariable &operator++();
  ExpressionVariable &operator--();
  ExpressionVariable &operator+=(double value);
  ExpressionVariable &operator-=(double value);
  ExpressionVariable &operator++(int value);
  ExpressionVariable &operator--(int value);
  double calculate() override;
  virtual ~ExpressionVariable() = default;
 private:
  string varname;
  double varvalue;
};

#endif //EX1__EXPRESSIONVARIABLE_H_
