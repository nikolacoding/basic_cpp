#include "Cat.h"

Cat::Cat(){
    this->m_age = 15;
    this->m_mass = 5;
}

void Cat::makeSound() const{
    std::cout << "meow!" << std::endl;
}