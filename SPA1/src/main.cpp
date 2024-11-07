#include <iostream>

#include "Utility.h"
#include "Simulation.h"

int main(void){
    Utility::RandomizeSeed();

    int n, type;
    std::cout << "Unesi broj vozila za simulaciju: ";
    std::cin >> n;

    std::cout << "Unesi tip simulacije (1: putnicka vozila, 2: teretna vozila): ";
    std::cin >> type;

    Simulation::Run(n, type, 10);
}