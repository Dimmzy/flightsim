#include "VariableManager.h"

/**
 * Adds a variable to our symbolTable
 * @param str the Name of the variable we'll be referred to from the file
 * @param var the variable object.
 */
void VariableManager::addSymbol(std::string str, Variable *var) {
  this->symbolTable.insert(std::pair<std::string,Variable*>(str,var));
}
/**
 * Adds a Variable to our boundTable
 * @param str the Path of the variable in the simulator
 * @param var the variable object.
 */
void VariableManager::addBoundTable(std::string str, Variable *var) {
  this->boundTable.insert(std::pair<std::string,Variable*>(str,var));
}
/**
 * @return our SymbolTable map. [Client -> Simulator]
 */
std::map<std::string, Variable *> VariableManager::getSymbolTable() {
  return this->symbolTable;
}
/**
 * @return our BoundVariable map. [Simulator -> Server]
 */
std::map<std::string, Variable *> VariableManager::getBoundTable() {
  return this->boundTable;
}

/*
 * Populates our XMLVars vector with the predefined XML paths our simulator will send.
 */
VariableManager::VariableManager() {
  this->XMLVars.emplace_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
  this->XMLVars.emplace_back("/sim/time/warp");
  this->XMLVars.emplace_back("/controls/switches/magnetos");
  this->XMLVars.emplace_back("/instrumentation/heading-indicator/offset-deg");
  this->XMLVars.emplace_back("/instrumentation/altimeter/indicated-altitude-ft");
  this->XMLVars.emplace_back("/instrumentation/altimeter/pressure-alt-ft");
  this->XMLVars.emplace_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
  this->XMLVars.emplace_back("/instrumentation/attitude-indicator/indicated-roll-deg");
  this->XMLVars.emplace_back("/instrumentation/attitude-indicator/internal-pitch-deg");
  this->XMLVars.emplace_back("/instrumentation/attitude-indicator/internal-roll-deg");
  this->XMLVars.emplace_back("/instrumentation/encoder/indicated-altitude-ft");
  this->XMLVars.emplace_back("/instrumentation/encoder/pressure-alt-ft");
  this->XMLVars.emplace_back("/instrumentation/gps/indicated-altitude-ft");
  this->XMLVars.emplace_back("/instrumentation/gps/indicated-ground-speed-kt");
  this->XMLVars.emplace_back("/instrumentation/gps/indicated-vertical-speed");
  this->XMLVars.emplace_back("/instrumentation/heading-indicator/indicated-heading-deg");
  this->XMLVars.emplace_back("/instrumentation/magnetic-compass/indicated-heading-deg");
  this->XMLVars.emplace_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
  this->XMLVars.emplace_back("/instrumentation/turn-indicator/indicated-turn-rate");
  this->XMLVars.emplace_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
  this->XMLVars.emplace_back("/controls/flight/aileron");
  this->XMLVars.emplace_back("/controls/flight/elevator");
  this->XMLVars.emplace_back("/controls/flight/rudder");
  this->XMLVars.emplace_back("/controls/flight/flaps");
  this->XMLVars.emplace_back("/controls/engines/engine/throttle");
  this->XMLVars.emplace_back("/controls/engines/current-engine/throttle");
  this->XMLVars.emplace_back("/controls/switches/master-avionics");
  this->XMLVars.emplace_back("/controls/switches/starter");
  this->XMLVars.emplace_back("/engines/active-engine/auto-start");
  this->XMLVars.emplace_back("/controls/flight/speedbrake");
  this->XMLVars.emplace_back("/sim/model/c172p/brake-parking");
  this->XMLVars.emplace_back("/controls/engines/engine/primer");
  this->XMLVars.emplace_back("/controls/engines/current-engine/mixture");
  this->XMLVars.emplace_back("/controls/switches/master-bat");
  this->XMLVars.emplace_back("/controls/switches/master-alt");
  this->XMLVars.emplace_back("/engines/engine/rpm");
}
