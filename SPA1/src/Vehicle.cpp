#include "Vehicle.h"

static Passenger generatePassenger(int minAge = 0){
    int age = Utility::RandomInt(minAge, 70);
    return Passenger(age);
}

Vehicle::Vehicle(const int numPassengers){
    this->m_passengerVector.push_back(generatePassenger(18));
    for (int i = 0; i < numPassengers - 1; i++){
        this->m_passengerVector.push_back(generatePassenger());
    }
}

std::vector<Passenger>& Vehicle::getPassengersRef(){
    return this->m_passengerVector;
}