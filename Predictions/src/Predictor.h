#ifndef PREDICTOR_H
#define PREDICTOR_H

#include "Match.h"

#include <string>
#include <vector>

struct Predictor{
    std::string name;
    std::vector<std::pair<Match, unsigned short>> prediction;
};

#endif