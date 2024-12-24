#ifndef TRIP_H
#define TRIP_H

// pomocna privremena struktura cisto da se ne koristi std::pair<> 
// jer t.first i t.second ima manje smisla od t.from i t.to

struct Trip final {
    int from = -1;
    int to = -1;
};

#endif