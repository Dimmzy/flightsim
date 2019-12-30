

#include "ExpressionVariable.h"

#include <utility>

ExpressionVariable::ExpressionVariable(std::string name, double value) {
  this->varname = std::move(name);
  this->varvalue = value;
}
ExpressionVariable &ExpressionVariable::operator++() {
  this->varvalue++;
  return *this;
}
ExpressionVariable &ExpressionVariable::operator--() {
  this->varvalue--;
  return *this;
}
ExpressionVariable &ExpressionVariable::operator+=(double value) {
  this->varvalue += value;
  return *this;
}
ExpressionVariable &ExpressionVariable::operator-=(double value) {
  this->varvalue -= value;
  return *this;
}
ExpressionVariable &ExpressionVariable::operator++(int) {
  this->varvalue++;
  return *this;
}
ExpressionVariable &ExpressionVariable::operator--(int) {
  this->varvalue--;
  return *this;
}

double ExpressionVariable::calculate() {
  return this->varvalue;
}
