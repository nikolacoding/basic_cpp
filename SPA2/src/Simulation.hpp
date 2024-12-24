#ifndef SIMULATION_H
#define SIMULATION_H

#include <fstream>

#include "Graph.hpp"
#include "BST.hpp"

#include "Time.hpp"
#include "Stats.hpp"
#include "Utility.hpp"
#include "SimulationExceptions.hpp"

namespace Simulation {
    void Run(const string inputFolderName);
    static void MainLoop(Graph& graph, vector<Trip>& trips, vector<Vehicle>& vehicles, Time& time, Stats& stats);

    static void CheckForInputExceptions(Graph& graph, vector<Trip>& trips, vector<Vehicle>& vehicles);
    static Vehicle& getShortestTravelTime(vector<Vehicle>& vehicles, Graph& g);
    static inline int getTimeUntilArrival(const Vehicle& vehicle, Graph& g);
    static bool allVehiclesBusy(const vector<Vehicle>& vehicles);
    static void constructVehicleTree(int userLocation, int userDestination, BST& tree, 
        vector<Vehicle>& vehicles, Graph& graph);
    static void passTime(Time& time, vector<Vehicle>& vehicles, Graph& graph, Stats& stats, int numTripsRemaining);
    static void invokeVehicle(int userLocation, int userDestination, BST& tree, Graph& graph, Stats& stats);
}

#endif