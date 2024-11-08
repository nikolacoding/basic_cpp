#include "../passenger/PassengerVehicle.h"

int PassengerVehicle::m_numInstances = 1;

static Passenger generatePassenger(int minAge = 1){
    int age = Utility::RandomInt(minAge, 70);
    return Passenger(age);
}

PassengerVehicle::PassengerVehicle(const int numPassengers) : m_id(m_numInstances){
    if (numPassengers){
        m_numInstances++;
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

std::vector<Passenger>& PassengerVehicle::getPassengersRef() {
    return this->m_passengerVector;
}

int PassengerVehicle::getId() const {
    return this->m_id;
}

void PassengerVehicle::displayAllPassengers() const {
    for (Passenger p : m_passengerVector){
        std::printf("   Putnik [ID: %d] - %d god.\n", p.getId(), p.getAge());
    }
    std::printf("\n");
}