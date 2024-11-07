#include "Simulation.h"
using namespace Simulation;

#include "Passenger.h"      
#include "Vehicle.h"        
#include "LinkedList.h"     
#include "Queue.h"          
#include "Utility.h"        

void Simulation::Run(int numVehicles, int type){
    if (type != PUTNICKO && type != TERETNO){
        std::cout << "Tip simulacije nije validan.\n" << std::endl;
        return;
    }
    // TODO: prenijeti inicijalizaciju LinkedList u samu klasu Queue
    LinkedList* list = new LinkedList;
    Queue queue(list);

    if (type == PUTNICKO){

    }
}

void Simulation::End(){

}