#ifndef STATS_H
#define STATS_H

#include "Vehicle.hpp"

#include <vector>

struct Stats final {
    Stats(std::vector<Vehicle>& vehicles) : vehicles(vehicles) {}

    const std::vector<Vehicle>& vehicles;
    int totalUserWaitTime = 0;
    int totalUserTravelTime = 0;

    void incrementTotalTrips(Vehicle& vehicle, int value);
    void incrementTotalDistance(Vehicle& vehicle, int value);
    void logAllStats() const;
};

#endif