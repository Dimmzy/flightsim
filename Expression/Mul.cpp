

#include "Mul.h"
Mul::Mul(Expression *right, Expression *left) : BinaryOperator(right, left) {

}
double Mul::calculate() {
  return BinaryOperator::rightExp->calculate() * BinaryOperator::leftExp->calculate();
}
Mul::~Mul() {
  delete (BinaryOperator::leftExp);
  delete (BinaryOperator::rightExp);
}
