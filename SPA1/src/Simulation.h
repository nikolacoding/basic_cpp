#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <cstdio>
#include <fstream>
#include "shared/Utility.h"

// Putnicki dio simulacije
#include "passenger/Passenger.h"      
#include "passenger/PassengerVehicle.h"        
#include "passenger/PVListNode.h"
#include "passenger/PVLinkedList.h"
#include "passenger/PVQueue.h"
#include "passenger/PassengerListNode.h"
#include "passenger/PassengerLinkedList.h"
#include "passenger/PassengerQueue.h"

// Teretni dio simulacije
#include "cargo/Cargo.h"
#include "cargo/CargoStack.h"
#include "cargo/CargoVehicle.h"
#include "cargo/CVListNode.h"
#include "cargo/CVLinkedList.h"
#include "cargo/CVQueue.h"

namespace Simulation{

    // passenger vehicle
    void RunPV(const int numVehicles, const short priorityAgeThreshold);

    static void addVehiclesToPVQueue(PVQueue&, const int numVehicles, 
    const short priorityAgeThreshold);

    static void clearPVQueue(PVQueue& queue);

    // cargo vehicle
    void RunCV(const int numVehicles, const int numCargoTypes, const std::string filename);

    static bool addVehiclesToCVQueue(CVQueue&, const int numVehicles, 
    const int numCargoType, const std::string);

    static void clearCVQueue(CVQueue& queue);
}

#endif

// Nikola Markovic (2024)
// ETFBL, Strukture podataka i algoritmi, 2024/25.