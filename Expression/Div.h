
#ifndef EX1__DIV_H_
#define EX1__DIV_H_

#include "BinaryOperator.h"
class Div : public BinaryOperator {
 public:
  Div(Expression *right, Expression *left);
  double calculate();
  virtual ~Div();
};

#endif //EX1__DIV_H_
