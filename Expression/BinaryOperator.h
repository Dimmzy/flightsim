
#ifndef EX1__BINARYOPERATOR_H_
#define EX1__BINARYOPERATOR_H_

#include "Expression.h"
class BinaryOperator : public Expression {
 protected:
  Expression *rightExp;
  Expression *leftExp;
 public:
  BinaryOperator(Expression *right, Expression *left);
  virtual ~BinaryOperator() = default;
};

#endif //EX1__BINARYOPERATOR_H_
