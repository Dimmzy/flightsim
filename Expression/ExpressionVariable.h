#ifndef EX1__EXPRESSIONVARIABLE_H_
#define EX1__EXPRESSIONVARIABLE_H_

#include <string>
#include "Expression.h"

/**
 * ExpressionVariable class allows us to overload operators over our predefined variables and calculate the result.
 */
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
