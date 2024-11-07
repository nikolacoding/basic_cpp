#ifndef VEHICLE_H
#define VEHICLE_H

#include "Passenger.h"
#include "Utility.h"
#include <vector>

class Vehicle{
private:
    std::vector<Passenger> m_passengerVector;

public:
    Vehicle(int numPassengers = 1);
    bool hasChild(short threshold);
    std::vector<Passenger>& getPassengersRef();
    static Vehicle invalidVehicle;
    bool isInvalid();
};

#endif