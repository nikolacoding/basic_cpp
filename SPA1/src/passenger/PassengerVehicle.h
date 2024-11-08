#ifndef PASSENGERVEHICLE_H
#define PASSENGERVEHICLE_H

#include "../shared/Utility.h"
#include "../passenger/Passenger.h"
#include <vector>

class PassengerVehicle{
private:
    static int m_numInstances;
    int m_id;
    std::vector<Passenger> m_passengerVector;

public:
    PassengerVehicle(int numPassengers = 0);

    int getId() const;
    std::vector<Passenger>& getPassengersRef();
    bool hasChild(const short threshold);

    void displayAllPassengers() const;
};

#endif