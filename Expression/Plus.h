#ifndef EX1__PLUS_H_
#define EX1__PLUS_H_

#include "BinaryOperator.h"

/**
 * Plus binary operator that calculates the sum of two Expressions.
 */
class Plus : public BinaryOperator {
 public:
  Plus(Expression *left, Expression *right);
  double calculate();
  virtual ~Plus();
};

#endif //EX1__PLUS_H_
