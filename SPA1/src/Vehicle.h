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
    std::vector<Passenger>& getPassengersRef();
};

#endif