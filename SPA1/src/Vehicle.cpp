#include "Vehicle.h"

Vehicle Vehicle::invalidVehicle = Vehicle(0);

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

bool Vehicle::hasChild(short threshold){
    std::vector<Passenger>& passengers = this->getPassengersRef();

    for (Passenger p : passengers){
        if (p.getAge() <= threshold)
            return true;
    }
    return false;
}

std::vector<Passenger>& Vehicle::getPassengersRef(){
    return this->m_passengerVector;
}

bool Vehicle::isInvalid(){
    return this->getPassengersRef().size() == 0;
}