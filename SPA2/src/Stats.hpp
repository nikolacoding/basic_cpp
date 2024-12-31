#ifndef STATS_H
#define STATS_H

#include "Vehicle.hpp"
#include "Trip.hpp"
#include "Graph.hpp"

#include <vector>
using std::vector;

struct Stats final {
    Stats(std::vector<Vehicle>& vehicles) : vehicles(vehicles) {}

    const std::vector<Vehicle>& vehicles;
    int totalUserWaitTime = 0;
    int totalUserTravelTime = 0;

    void incrementTotalTrips(Vehicle& vehicle, int value);
    void incrementTotalDistance(Vehicle& vehicle, int value);
    void logAllStats(Graph& graph, vector<Trip>& allTrips) const;
};

#endif