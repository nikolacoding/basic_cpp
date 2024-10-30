#include "Receiver.h"

Receiver::Receiver(){

}

Receiver::~Receiver(){

}

std::string Receiver::getName() const{
    return this->_name;
}

int Receiver::getEta() const{
    return this->_eta;
}

int Receiver::getWaitTime() const{
    return this->_waitTime;
}

int Receiver::getDistance() const{
    return this->_distanceFromStorage;
}