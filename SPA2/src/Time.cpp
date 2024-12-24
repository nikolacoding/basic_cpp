#include "Time.hpp"

// vremenski skok koji se poziva dok korisnik bez slobodnog vozila ceka na prvo slobodno
void Time::jump(int units, Stats& stats){
    for (auto& vehicle : this->m_vehicles){
        vehicle.elapsed += units;
        this->update(vehicle, stats);
    }
}

// evaluacija da li je neka voznja zavrsena u zavisnosti od toga da li je
// vehicle.elapsed premasilo dist(vehicle.location, vehicle.destination)
// ovo se poziva nakon svakog vremenskog skoka za svako pojedinacno vozilo
void Time::update(Vehicle& vehicle, Stats& stats){

    // protok vremena nije relevantan kod pasivnih vozila
    if (vehicle.busy){
        int baseDistance = m_graph.getDistanceFromTo(vehicle.location, vehicle.destination);
        int elapsed = vehicle.elapsed;

        if (elapsed - baseDistance >= 0){
            int distance = m_graph.getDistanceFromTo(vehicle.userLocation, vehicle.destination);
            std::string path = m_graph.getPathFromTo(vehicle.userLocation, vehicle.destination);

            std::printf(">> %s [ID: %d] je zavrsilo voznju na putanji: %s [dist: %d]\n",
            vehicle.name.c_str(), vehicle.id, path.c_str(), distance);

            stats.totalUserTravelTime += distance;
            stats.incrementTotalTrips(vehicle, 1);
            stats.incrementTotalDistance(vehicle, distance);

            vehicle.busy = false;
            vehicle.location = vehicle.destination;
            vehicle.userLocation = -1;
            vehicle.destination = -1;
        }
    }
}