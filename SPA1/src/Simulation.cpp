#include "Simulation.h"
using namespace Simulation;

#include "Passenger.h"      
#include "Vehicle.h"        
#include "LinkedList.h"     
#include "Queue.h"          
#include "Utility.h"        

static void addVehiclesToQueue(Queue& queue, const int numVehicles, const short priorityAgeThreshold){
    for (int i = 0; i < numVehicles; i++){
        int numPassengers = Utility::RandomInt(1, 5);
        Vehicle newVehicle(numPassengers);

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

static void clearQueue(Queue& queue){
    auto checkPassport = [](Vehicle vehicle) -> void{
        std::vector<Passenger>& passengers = vehicle.getPassengersRef();
        std::cout << passengers.size() << " putnika: " << std::endl;
        
        for (Passenger p : passengers){
            std::cout << "Pregled pasosa putnika " << p.getId() << 
            " (" << p.getAge() << ") godina." << std::endl;
        }
    };

    bool success;
    do{
        Vehicle current = queue.dequeue(success);
        std::cout << "Novo vozilo na redu, ";
        checkPassport(current);
    } while (success);
}

void Simulation::Run(const int numVehicles, const int type, const short priorityAgeThreshold){
    if (type != PUTNICKO && type != TERETNO){
        std::cout << "Tip simulacije nije validan.\n" << std::endl;
        return;
    }
    // TODO: prenijeti inicijalizaciju LinkedList u samu klasu Queue
    LinkedList* list = new LinkedList;
    Queue queue(list);

    if (type == PUTNICKO){
        std::cout << "Pokrecemo simulaciju sa " << numVehicles << " vozila." << std::endl;
        addVehiclesToQueue(queue, numVehicles, priorityAgeThreshold);
        clearQueue(queue);
    }
}

void Simulation::End(){

}