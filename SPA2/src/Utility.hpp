#ifndef UTILITY_H
#define UTILITY_H

#include "Vehicle.hpp"
#include "Trip.hpp"

#include <fstream>
#include <string>
#include <map>
#include <vector>

using std::vector;
using std::string;
using std::ifstream;

namespace Utility{
    // provjere za izuzetke
    int getLargestVehicleLocation(const vector<Vehicle>& vehicles);
    int getSmallestVehicleLocation(const vector<Vehicle>& vehicles);
    int getLargestTripLocation(const vector<Trip>& trips);
    int getSmallestTripLocation(const vector<Trip>& trips);
    bool checkForVehicleStartLocationOverlaps(const vector<Vehicle>& vehicles);

    int getCSVLineIntCount(const string line);
    vector<int> parseCSVLineToIntVector(string line);
    vector<string> getAllCSVLinesFromFile(ifstream& file);
    vector<Trip> getTripsFromCSVFile(ifstream& file);
    vector<Vehicle> getVehiclesFromCSVFile(ifstream& file);
}

#endif