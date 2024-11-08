#include <iostream>

#include "shared/Utility.h"
#include "Simulation.h"

// TODO: implementirati i testirati CargoStack prije bilo cega ostalog

int main(void){
    Utility::RandomizeSeed();

    int n, type;
    std::cout << "Unesi broj vozila za simulaciju: ";
    std::cin >> n;
    
    std::cout << "Unesi tip simulacije (1: putnicka vozila, 2: teretna vozila): ";
    std::cin >> type;
    
    Simulation::Run(n, type, 10);
}