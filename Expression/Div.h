#ifndef EX1__DIV_H_
#define EX1__DIV_H_

#include "BinaryOperator.h"

/**
 * Divides the two expressions and calculates the result.
 */
class Div : public BinaryOperator {
 public:
  Div(Expression *right, Expression *left);
  double calculate() override;
  virtual ~Div();
};

#endif //EX1__DIV_H_
