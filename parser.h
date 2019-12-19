
#ifndef FLIGHTSIM_PARSER_H
#define FLIGHTSIM_PARSER_H
#include "flightSim.h"


class parser {
public:
    parser(const vector<string> &tokens, flightSim* sim);

private:
    vector<string> tokens;
    flightSim*   sim;
    void parse();
    void parseVar(int i);

};


#endif //FLIGHTSIM_PARSER_H
