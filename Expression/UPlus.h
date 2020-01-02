#ifndef EX1__UPLUS_H_
#define EX1__UPLUS_H_

#include "UnaryOperator.h"
#include "Value.h"

/**
 * Unary Plus operator that calculates the Expressions value (basically the same as no operator)
 */
class UPlus : public UnaryOperator {
 public:
  UPlus(Expression *exp);
  double calculate();
  virtual ~UPlus();
};

#endif //EX1__UPLUS_H_
