#ifndef EX1__VALUE_H_
#define EX1__VALUE_H_

#include "Expression.h"

/**
 * Holds the value of a given Expression.
 */
class Value : public Expression {
 private:
  const double value;
 public:
  explicit Value(double val);
  double calculate() override;
  virtual ~Value() = default;
};

#endif //EX1__VALUE_H_
