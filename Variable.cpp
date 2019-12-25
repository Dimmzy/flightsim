
#include "Variable.h"

double Variable::getValue() {
  return this->value;
}
std::string Variable::getPath() {
  return this->simPath;
}
void Variable::setValue(double val) {
  this->value = val;
}
void Variable::setPath(std::string path) {
  this->simPath = path;
}
Variable::Variable(double value, const std::string &sim_path) : value(value), simPath(sim_path) {}
