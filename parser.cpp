#include "parser.h"

#include <utility>



void parser::parse() {
    for (int i = 0; i < this->tokens.size(); i++) {
        if (tokens.at(i) == "var") {
            parseVar(i);
            continue;
        }
    }
}

void parser::parseVar(int index) {

}

parser::parser(const vector<string> &tokens, flightSim* sim) {
    this->tokens = tokens;
    this->sim = sim;
}


