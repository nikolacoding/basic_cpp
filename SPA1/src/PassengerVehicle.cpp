#include "PassengerVehicle.h"

static Passenger generatePassenger(int minAge = 1){
    int age = Utility::RandomInt(minAge, 70);
    return Passenger(age);
}

PassengerVehicle::PassengerVehicle(const int numPassengers){
    if (numPassengers){
        this->m_passengerVector.push_back(generatePassenger(18));
        for (int i = 0; i < numPassengers - 1; i++){
            this->m_passengerVector.push_back(generatePassenger());
        }
    }
}

bool PassengerVehicle::hasChild(const short threshold){
    std::vector<Passenger>& passengers = this->getPassengersRef();

    for (Passenger p : passengers){
        if (p.getAge() <= threshold)
            return true;
    }
    return false;
}

std::vector<Passenger>& PassengerVehicle::getPassengersRef(){
    return this->m_passengerVector;
}