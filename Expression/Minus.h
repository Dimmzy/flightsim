

#ifndef EX1__MINUS_H_
#define EX1__MINUS_H_

#include "BinaryOperator.h"
class Minus : public BinaryOperator {
 public:
  Minus(Expression *right, Expression *left);
  double calculate();
  virtual ~Minus();
};

#endif //EX1__MINUS_H_
