

#include "Div.h"
Div::Div(Expression *right, Expression *left) : BinaryOperator(right, left) {

}
double Div::calculate() {
  // Division by zero
  if (BinaryOperator::leftExp->calculate() == 0) {
    throw "bad input"; // fix this shit
  }
  return BinaryOperator::rightExp->calculate() / BinaryOperator::leftExp->calculate();
}
Div::~Div() {
  delete (BinaryOperator::leftExp);
  delete (BinaryOperator::rightExp);
}

