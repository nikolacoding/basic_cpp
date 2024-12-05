#include "Dog.h"

Dog::Dog(){
    this->m_age = 20;
    this->m_mass = 15;
}

void Dog::makeSound() const {
    std::cout << "woof!" << std::endl;
}