#ifndef EX1__UNARYOPERATOR_H_
#define EX1__UNARYOPERATOR_H_

#include "Expression.h"

/**
 * Unary operator interface that allows us to implement Unary operators.
 */
class UnaryOperator : public Expression {
 protected:
  Expression *express;
 public:
  explicit UnaryOperator(Expression *exp);
  virtual ~UnaryOperator() = default;
};

#endif //EX1__UNARYOPERATOR_H_
