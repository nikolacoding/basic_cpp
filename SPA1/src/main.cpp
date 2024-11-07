#include <iostream>

#include "Passenger.h"      // testirano
#include "Vehicle.h"        // testirano
#include "LinkedList.h"     // testirano
#include "Queue.h"          // testirano
#include "Utility.h"        // testirano
#include "Simulation.h"     // testirano 1/2

int main(void){
    Utility::RandomizeSeed();
    Simulation::Run(5, Simulation::Types::PUTNICKO, 10);
}