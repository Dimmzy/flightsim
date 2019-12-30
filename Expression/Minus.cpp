

#include "Minus.h"
Minus::Minus(Expression *right, Expression *left) : BinaryOperator(left, right) {

}
double Minus::calculate() {
  return BinaryOperator::rightExp->calculate() - BinaryOperator::leftExp->calculate();
}
Minus::~Minus() {
  delete (BinaryOperator::leftExp);
  delete (BinaryOperator::rightExp);
}
