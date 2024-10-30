#include "Export.h"

Export::Export(std::string name) : _name(name) {
    // logika nasumicne inicijalizacije _maxCapacity i _speed
}

Export::~Export(){
    
}

std::string Export::getName() const {
    return this->_name;
}

int Export::getMaxCapacity() const {
    return this->_maxCapacity;
}

int Export::getMaxSpeed() const {
    return this->_maxSpeed;
}