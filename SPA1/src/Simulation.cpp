#include "Simulation.h"
using namespace Simulation;     

void Simulation::RunPV(const int numVehicles, const short priorityAgeThreshold){
    PVQueue PVQueue;
    std::cout << "Pokrecemo simulaciju sa " << numVehicles << " putnickih vozila." << std::endl;
    addVehiclesToPVQueue(PVQueue, numVehicles, priorityAgeThreshold);
    clearPVQueue(PVQueue);
}

void Simulation::RunCV(const int numVehicles, const int numCargoTypes){
    CVQueue CVQueue;
    std::cout << "Pokrecemo simulaciju sa " << numVehicles << " teretnih vozila." << std::endl;
    if (addVehiclesToCVQueue(CVQueue, numVehicles, numCargoTypes))
        clearCVQueue(CVQueue);
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
            std::printf("Pregled pasosa putnika %d (%d godina)...\n",
            p.getId(), p.getAge());
        }
    };
    
    PassengerVehicle current;
    while(queue.dequeue(current)){
        std::cout << "Novo vozilo na redu, ";
        checkPassport(current);
    }
}

static bool Simulation::addVehiclesToCVQueue(CVQueue& queue, 
const int numVehicles, const int numCargoTypes){

    // TODO: korisnicki definisana datoteka
    std::ifstream file("roba.txt");
    if (!file.is_open()){
        std::cout << "Datoteka sa robom se ne moze otvoriti." << std::endl;
        return false;
    }

    auto getRandomCargoNames = [](std::ifstream& stream) -> std::vector<std::string>{
        std::string currentLine;
        std::vector<std::string> ret;
        while (std::getline(stream, currentLine)){
            ret.push_back(currentLine);   
        }
        stream.close();
        return ret;
    };

    std::vector<std::string> cargoNames = getRandomCargoNames(file);

    for (int i = 0; i < numVehicles; i++){
        std::vector<std::string> randomPickedCargoNames = Utility::randomUnique(cargoNames, numCargoTypes);

        std::vector<Cargo> randomCargo;
        for (std::string s : randomPickedCargoNames)
            randomCargo.push_back(Cargo(s));
    
        CargoVehicle newVehicle(randomCargo);

        std::printf("U red ulazi teretno vozilo [ID: %d]\n", newVehicle.getId());
        std::printf("Roba:\n");
        newVehicle.logCargo();
        queue.enqueue(newVehicle);
    }
    return true;
}

static void Simulation::clearCVQueue(CVQueue& queue){
    queue.displayAll();

    CargoVehicle currentVehicle;
    CargoStack tableStack;
    while (queue.dequeue(currentVehicle)){
        std::printf("Pocinje proces pregleda robe za vozilo ID:%d\n",
        currentVehicle.getId());

        CargoStack& currentStack = currentVehicle.m_cargoStack;
        Cargo currentCargo;
        while (currentStack.pop(currentCargo)){
            std::cout << "Iz prikolice istovaramo " << currentCargo.getName() <<
            " i stavljamo na sto." << std::endl;
            tableStack.push(currentCargo);
        }
        std::printf("Uspjesno pregledanje robe za vozilo ID:%d\n",
        currentVehicle.getId());

        while (tableStack.pop(currentCargo)){
            std::cout << "Vracamo " << currentCargo.getName() <<
            " sa stola nazad u prikolicu." << std::endl;
        }

        printf("Teretno vozilo ID:%d je pusteno preko granice.\n",
        currentVehicle.getId());
    }
}