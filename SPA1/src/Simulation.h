#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "Utility.h"

// Putnicki dio simulacije
#include "Passenger.h"      
#include "PassengerVehicle.h"        
#include "PVLinkedList.h"
#include "PVQueue.h"  

// Teretni dio simulacije
#include "Cargo.h"
#include "CargoVehicle.h"
#include "CVLinkedList.h"
#include "CVQueue.h"   

namespace Simulation{
    enum Types{
        PUTNICKO = 1,
        TERETNO = 2
    };

    static void addVehiclesToPVQueue(PVQueue&, const int, const short);
    static void clearPVQueue(PVQueue& PVQueue);

    void Run(const int numVehicles, const int type, const short priorityAgeThreshold);
}

#endif