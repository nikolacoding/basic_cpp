#include <iostream>

#include "shared/Utility.h"
#include "Simulation.h"

int main(void){
    Utility::RandomizeSeed();

    int n, type;
    enum Types { PUTNICKA = 1, TERETNA = 2 };

    std::cout << "Unesi tip simulacije (1: putnicka vozila, 2: teretna vozila): ";
    std::cin >> type;

    std::cout << "Unesi broj vozila za simulaciju: ";
    std::cin >> n;

    switch(type){
        case PUTNICKA:
        {            
            Simulation::RunPV(n, 10);
            break;
        }
        case TERETNA:
        {            
            std::string filename;

            // podrazumijevana putanja je {ovaj direktorijum}/../cargo_types/{filename}
            std::cout << "Naziv datoteke s robom: ";
            std::cin >> filename;
            Simulation::RunCV(n, 3, filename);
            break;
        }
        default:
            std::cout << "Uneseni tip simulacije nije validan." << std::endl;
            break;
    }
}

// Nikola Markovic (2024)
// ETFBL, Strukture podataka i algoritmi, 2024/25.