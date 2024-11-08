#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <cstdio>
#include <fstream>
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
    // passenger vehicle
    void RunPV(const int numVehicles, const short priorityAgeThreshold);
    static void addVehiclesToPVQueue(PVQueue&, const int, const short);
    static void clearPVQueue(PVQueue& queue);

    // cargo vehicle
    void RunCV(const int numVehicles, const int numCargoTypes);
    static bool addVehiclesToCVQueue(CVQueue& queue, const int, const int);
    static void clearCVQueue(CVQueue& queue);

    // addVehiclesToCVQueue vraca bool kao mjeru uspjeha otvaranja datoteke
    // da znamo da li ostatak programa moze da nastavi normalno
}

#endif