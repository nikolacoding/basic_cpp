#ifndef PASSENGERVEHICLE_H
#define PASSENGERVEHICLE_H

#include "Passenger.h"
#include "Utility.h"
#include <vector>

class PassengerVehicle{
private:
    std::vector<Passenger> m_passengerVector;

public:
    PassengerVehicle(int numPassengers = 0);
    bool hasChild(const short threshold);
    std::vector<Passenger>& getPassengersRef();

};

#endif