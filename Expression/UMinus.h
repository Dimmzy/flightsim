

#ifndef EX1__UMINUS_H_
#define EX1__UMINUS_H_

#include "UnaryOperator.h"
#include "Value.h"
class UMinus : public UnaryOperator {
 public:
  UMinus(Expression *express);
  double calculate();
  virtual ~UMinus();
};

#endif //EX1__UMINUS_H_
