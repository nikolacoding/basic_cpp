#include "Dog.h"

Animal* Dog::clone() const {
    return new Dog(*this);
}

void Dog::sound() const {
    std::cout << "woof!" << std::endl;
}

void Dog::scale(const double q){
    this->m_height *= q;
    this->m_weight *= q;
}

void Dog::add(const Animal& other){
    this->m_height += other.getHeight();
    this->m_weight += other.getWeight();
}