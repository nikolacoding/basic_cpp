#ifndef TIME_H
#define TIME_H

#include "Vehicle.hpp"
#include "Graph.hpp"
#include "Stats.hpp"

#include <vector>

struct Time final {
public:
    Time(std::vector<Vehicle>& vehicles, Graph& graph) : 
        m_vehicles(vehicles), m_graph(graph) {}

    void jump(int units, Stats& stats);
    void update(Vehicle& vehicle, Stats& stats);
private:
    const Graph& m_graph;
    std::vector<Vehicle>& m_vehicles;
};

#endif