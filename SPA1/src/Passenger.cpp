#include "Passenger.h"

int Passenger::m_totalInstances = 1;

Passenger::Passenger(short age) : m_age(age), m_id(m_totalInstances){
    Passenger::m_totalInstances++;
}

short Passenger::getAge() const {
    return this->m_age;
}

int Passenger::getId() const {
    return this->m_id;
}

void Passenger::debugLog(){
    std::cout << "Putnik " << this->getId() << ": " << this->getAge() << " godina." << std::endl;
}