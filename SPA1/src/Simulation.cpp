#include "Simulation.h"
using namespace Simulation;     

void Simulation::Run(const int numVehicles, const int type, const short priorityAgeThreshold){
    if (type != PUTNICKO && type != TERETNO){
        std::cout << "Tip simulacije nije validan.\n" << std::endl;
        return;
    }

    if (type == PUTNICKO){
        PVQueue PVQueue;
        std::cout << "Pokrecemo simulaciju sa " << numVehicles << " putnickih vozila." << std::endl;
        addVehiclesToPVQueue(PVQueue, numVehicles, priorityAgeThreshold);
        clearPVQueue(PVQueue);
    }
    else if (type == TERETNO){
        std::cout << "Pokrecemo simulaciju sa " << numVehicles << " teretnih vozila." << std::endl;
    }
}

static void Simulation::addVehiclesToPVQueue(PVQueue& queue, const int numVehicles, const short priorityAgeThreshold){
    for (int i = 0; i < numVehicles; i++){
        int numPassengers = Utility::RandomInt(1, 5);
        PassengerVehicle newVehicle(numPassengers);

        std::cout << "U red ";

        if (newVehicle.hasChild(priorityAgeThreshold)){
            queue.enqueuePriority(newVehicle);
            std::cout << "prioritetno ";
        }
        else{
            queue.enqueue(newVehicle);
        }
        std::cout << "ulazi vozilo sa " << numPassengers << " putnika." << std::endl;
    }
}

static void Simulation::clearPVQueue(PVQueue& queue){
    auto checkPassport = [](PassengerVehicle& vehicle) -> void{
        std::vector<Passenger>& passengers = vehicle.getPassengersRef();
        std::cout << passengers.size() << " putnika: " << std::endl;
        
        for (Passenger p : passengers){
            std::cout << "Pregled pasosa putnika " << p.getId() << 
            " (" << p.getAge() << ") godina." << std::endl;
        }
    };
    
    PassengerVehicle current;
    while(queue.dequeue(current)){
        std::cout << "Novo vozilo na redu, ";
        checkPassport(current);
    }
}

static void Simulation::addVehiclesToCVQueue(CVQueue& queue){
    // TODO: dodati vozila u red
    // vozila u konstruktoru kreairaju stek robe analogno
    // putnickim vozilima koji u konstruktoru kreairaju vektor putnika
}

static void Simulation::clearCVQueue(CVQueue& queue){
    // TODO: 
}