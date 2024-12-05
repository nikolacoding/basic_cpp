#include "Sheep.h"

Sheep::Sheep(){
    this->m_age = 10;
    this->m_mass = 75;
}

void Sheep::makeSound() const {
    std::cout << "baaa!" << std::endl;
}