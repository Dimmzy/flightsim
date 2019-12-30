
#include "BinaryOperator.h"
BinaryOperator::BinaryOperator(Expression *right, Expression *left) {
  this->leftExp = left;
  this->rightExp = right;
}
