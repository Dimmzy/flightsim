#include "Div.h"

Div::Div(Expression *right, Expression *left) : BinaryOperator(right, left) {}

double Div::calculate() {
  // Division by zero
  if (BinaryOperator::rightExp->calculate() == 0) {
    throw "bad input";
  }
  if (BinaryOperator::leftExp->calculate() == 0) {
    return 0;
  }
  return BinaryOperator::leftExp->calculate() / BinaryOperator::rightExp->calculate();
}

Div::~Div() {
  delete (BinaryOperator::leftExp);
  delete (BinaryOperator::rightExp);
}

