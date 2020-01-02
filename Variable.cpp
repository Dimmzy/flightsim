
#include "Variable.h"

/**
 * @return Value of the variable as double.
 */
double Variable::getValue() {
  return this->value;
}
/**
 * @return The path of the variable in the simulator as a string.
 */
std::string Variable::getPath() {
  return this->simPath;
}
/**
 * Sets the variable's value to the passed value.
 * @param val The variable's new value.
 */
void Variable::setValue(double val) {
  this->value = val;
}
/**
 * Constructs the Variable
 * @param value the initial value of the Variable (usually 0).
 * @param sim_path the path of the variable in the simulator.
 */
Variable::Variable(double value, const std::string &sim_path) : value(value), simPath(sim_path) {}
