#include <iostream>

#include "shared/Utility.h"
#include "Simulation.h"

// TODO: implementirati i testirati Cargo i CargoStack prije bilo cega ostalog

// TODO: (na kraju svega) neke QoL stavke -
//      1) zamijeniti std::cout sa std::printf iz <cstdio> zarad lakseg pregledanja
//          ali obratiti paznju da printf ne prihvata C++ stil stringova
//      2) izbaciti metode viska (mislim da ih postoji nekoliko) zbog
//          redundancije ili prosto sto se nikad ne pozivaju
//      3) provjeriti edge kejsove kod implementacija ovih struktura posto
//          mislim da sam preskocio postavku dosta "ograde" oko nekih od njih
//          jer znam da nece biti koristene van predvidjenog opsega, ali je 
//          dobra praksa

int main(void){
    Utility::RandomizeSeed();
//
    //int n, type;
    //std::cout << "Unesi broj vozila za simulaciju: ";
    //std::cin >> n;
    //
    //std::cout << "Unesi tip simulacije (1: putnicka vozila, 2: teretna vozila): ";
    //std::cin >> type;
    //
    // TODO: RunCV-u dodati parametar koji uzima korisnicki definisan naziv
    // datoteke, te je kasnije otvara
    Simulation::RunCV(5, 3);
}