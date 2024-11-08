#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "shared/Utility.h"

// Putnicki dio simulacije
#include "passenger/Passenger.h"      
#include "passenger/PassengerVehicle.h"        
#include "passenger/PVLinkedList.h"
#include "passenger/PVQueue.h"  

// Teretni dio simulacije
#include "cargo/Cargo.h"
#include "cargo/CargoVehicle.h"
#include "cargo/CVLinkedList.h"
#include "cargo/CVQueue.h"   

namespace Simulation{
    enum Types{
        PUTNICKO = 1,
        TERETNO = 2
    };

    static void addVehiclesToPVQueue(PVQueue&, const int, const short);
    static void clearPVQueue(PVQueue& queue);

    static void addVehiclesToCVQueue(CVQueue& queue);
    static void clearCVQueue(CVQueue& queue);

    void Run(const int numVehicles, const int type, const short priorityAgeThreshold);
}

#endif