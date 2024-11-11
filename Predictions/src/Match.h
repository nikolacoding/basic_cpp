#ifndef MATCH_H
#define MATCH_H

#include "Team.h"
#include <utility>

struct Match{
    std::pair<Team, Team> teams;
    unsigned short winner;
};

#endif