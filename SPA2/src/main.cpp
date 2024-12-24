#include "Simulation.hpp"

int main(void){
    try{
        Simulation::Run("default");
                         // ^ default - podrazumijevane ulazne datoteke
                         // ^ custom - licno kreirane ulazne datoteke
    } catch (std::exception& exception){
        std::cout << exception.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}