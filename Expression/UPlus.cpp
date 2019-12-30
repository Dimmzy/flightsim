

#include "UPlus.h"
UPlus::UPlus(Expression *exp) : UnaryOperator(exp) {

}
double UPlus::calculate() {
  return UnaryOperator::express->calculate();
}
UPlus::~UPlus() {
  delete (UnaryOperator::express);
}
