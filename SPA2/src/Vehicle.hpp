#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using std::string;

struct Vehicle final {
    Vehicle(int id, string name, int location) : id(id), name(name), location(location) {}

    const int id;
    string name = "";
    
    // vrijeme dolaska ne postoji kao eksplicitan atribut vec se proracunava po potrebi
    int location = -1;
    int userLocation = -1;
    int destination = -1;

    bool busy = false;
    int elapsed = 0;

friend class Stats;
private:
    int totalTrips = 0;
    int totalDistance = 0;
};

#endif