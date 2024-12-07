#include "Animal.h"

Animal* Animal::operator*(const double q) const {
    Animal* newObj = this->clone();
    newObj->scale(q);
    return newObj;
}

void Animal::operator*=(const double q){
    this->scale(q);
}

Animal* Animal::operator+(const Animal& other) const {
    Animal* newObj = this->clone();
    newObj->add(other);
    return newObj;
}

void Animal::operator+=(const Animal& other){
    this->add(other);
}

void Animal::logMetrics() const {
    std::printf("h: %.1lf, w: %.1lf\n", this->m_height, this->m_weight);
}