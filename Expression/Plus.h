

#ifndef EX1__PLUS_H_
#define EX1__PLUS_H_

#include "BinaryOperator.h"
class Plus : public BinaryOperator {
 public:
  Plus(Expression *left, Expression *right);
  double calculate();
  virtual ~Plus();
};

#endif //EX1__PLUS_H_
