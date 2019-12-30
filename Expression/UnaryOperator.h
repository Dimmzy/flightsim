

#ifndef EX1__UNARYOPERATOR_H_
#define EX1__UNARYOPERATOR_H_
#include "Expression.h"

class UnaryOperator : public Expression {
 protected:
  Expression *express;
 public:
  explicit UnaryOperator(Expression *exp);
  virtual ~UnaryOperator() = default;
};

#endif //EX1__UNARYOPERATOR_H_
