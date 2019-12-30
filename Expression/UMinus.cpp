

#include "UMinus.h"

UMinus::UMinus(Expression *exp) : UnaryOperator(exp) {

}
double UMinus::calculate() {
  return -(UnaryOperator::express->calculate());
}
UMinus::~UMinus() {
  delete (UnaryOperator::express);
}
