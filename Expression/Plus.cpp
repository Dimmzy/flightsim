

#include "Plus.h"
Plus::Plus(Expression *right, Expression *left) : BinaryOperator(right, left) {
}
double Plus::calculate() {
  return BinaryOperator::rightExp->calculate() + BinaryOperator::leftExp->calculate();
}
Plus::~Plus() {
  delete (BinaryOperator::leftExp);
  delete (BinaryOperator::rightExp);
}
