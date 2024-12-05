#include "Animal.h"

Animal::Animal(){
    m_age = 1;
    m_mass = 1;
}

void Animal::logInfo() const {
    std::printf("m: %.1lfkg, e.a: %dy\n", this->m_mass, this->m_age);
}