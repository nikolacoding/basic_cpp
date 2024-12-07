#include "Cat.h"

Animal* Cat::clone() const {
    return new Cat(*this);
}

void Cat::sound() const {
    std::cout << "meow!" << std::endl;
}

void Cat::scale(const double q){
    this->m_height *= q;
    this->m_weight *= q;
}

void Cat::add(const Animal& other){
    this->m_height += other.getHeight();
    this->m_weight += other.getWeight();
}