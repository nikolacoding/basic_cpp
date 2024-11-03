#include "Export.h"
#include "Utility.h"

Export::Export(std::string name) : _name(name) {
    this->_currentLoad = 0;
    this->_maxCapacity = Utility::RandomInt(50, 200);
    this->_maxSpeed = Utility::RandomInt(50, 100);
}

Export::~Export(){
    
}

std::string Export::getName() const {
    return this->_name;
}

int Export::getMaxCapacity() const {
    return this->_maxCapacity;
}

int Export::getCurrentLoad() const {
    return this->_currentLoad;
}

int Export::getMaxSpeed() const {
    return this->_maxSpeed;
}

int Export::addToLoad(Package p){
    this->loadedPackages.push_back(p);
    this->_currentLoad += p.getMass();
}

int Export::removeFromLoad(Package p){

}