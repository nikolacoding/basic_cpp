#include "Stats.hpp"

#include <iostream>
using std::cout;
using std::endl;

void Stats::incrementTotalTrips(Vehicle& vehicle, int value){
    vehicle.totalTrips += value;
}

void Stats::incrementTotalDistance(Vehicle& vehicle, int value){
    vehicle.totalDistance += value;
}

// formatiran ispis kompletne statistike
void Stats::logAllStats() const {
    cout << "Ukupno vrijeme cekanja korisnika na taksi: " << this->totalUserWaitTime << endl;
    cout << "Ukupno vrijeme prevoza korisnika: " << this->totalUserTravelTime << endl;

    for (const auto& v : this->vehicles){
        cout << v.name << " [ID: " << v.id << "]: " << endl;
        cout << "   " << "Broj voznji: " << v.totalTrips << endl;
        cout << "   " << "Predjeni put: " << v.totalDistance << endl;
    }
}