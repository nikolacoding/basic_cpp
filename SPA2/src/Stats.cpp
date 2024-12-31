#include "Stats.hpp"

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void Stats::incrementTotalTrips(Vehicle& vehicle, int value){
    vehicle.totalTrips += value;
}

void Stats::incrementTotalDistance(Vehicle& vehicle, int value){
    vehicle.totalDistance += value;
}

// formatiran ispis kompletne statistike
void Stats::logAllStats(Graph& graph, vector<Trip>& allTrips) const {
    cout << "Ukupno vrijeme cekanja korisnika na taksi: " << this->totalUserWaitTime << endl;
    cout << "Ukupno vrijeme prevoza korisnika: " << this->totalUserTravelTime << endl;

    // Modifikacija:
    double averageWaitingTime = this->totalUserWaitTime / allTrips.size();
    cout << "Prosjecno vrijeme cekanja na taksi: " << averageWaitingTime << endl;

    int i = 0;
    for (const auto& t : allTrips){
        int current = graph.getDistanceFromTo(t.from, t.to);
        if (current < averageWaitingTime)
            std::printf("Voznja %d je trajala manje od prosjeka [%d < %.0lf]\n", i, current, averageWaitingTime);

        i++;
    }

    for (const auto& v : this->vehicles){
        cout << v.name << " [ID: " << v.id << "]: " << endl;
        cout << "   " << "Broj voznji: " << v.totalTrips << endl;
        cout << "   " << "Predjeni put: " << v.totalDistance << endl;
    }
}