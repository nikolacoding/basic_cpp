#ifndef PASSENGERVEHICLE_H
#define PASSENGERVEHICLE_H

#include "../shared/Utility.h"
#include "../passenger/Passenger.h"
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