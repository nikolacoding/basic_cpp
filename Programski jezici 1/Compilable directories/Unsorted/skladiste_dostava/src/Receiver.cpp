#include "Receiver.h"
#include "Utility.h"

Receiver::Receiver(std::string name) {
    _name = name;
    _eta = Utility::RandomInt(24, 72);
    _waitTime = 0;
    _distanceFromStorage = Utility::RandomInt(100, 400);
}

Receiver::~Receiver(){

}

std::string Receiver::getName() const {
    return this->_name;
}

int Receiver::getEta() const {
    return this->_eta;
}

int Receiver::getWaitTime() const {
    return this->_waitTime;
}

int Receiver::getDistance() const {
    return this->_distanceFromStorage;
}