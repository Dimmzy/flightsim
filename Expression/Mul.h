

#ifndef EX1__MUL_H_
#define EX1__MUL_H_

#include "BinaryOperator.h"
class Mul : public BinaryOperator {
 public:
  Mul(Expression *right, Expression *left);
  double calculate();
  virtual ~Mul();
};

#endif //EX1__MUL_H_
