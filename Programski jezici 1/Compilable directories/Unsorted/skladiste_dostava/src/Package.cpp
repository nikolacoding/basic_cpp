#include "Package.h"
#include "Utility.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

static std::vector<std::string> existingNames;

Package Package::emptyPackage = Package(-1, -1, -1, -1, -1);
int Package::_count = 0;

Package::Package(int margin) : _margin(margin){
    auto generateName = []() -> std::string {
        std::string name = "";

        do {
            // identical name found, rolling the randomizer again
            name = "";

            name += Utility::RandomLetter();
            name += '.';
            name += Utility::RandomLetter();
            name += '.';
        } while (std::find(existingNames.begin(), existingNames.end(), name) != existingNames.end());

        return name;
    };

    _id = ++_count;
    _mass = Utility::RandomInt(1, 20);
    _mpc = Utility::RandomInt(20, 100);
    _vpc = _mpc + (_mpc * _margin / 100); // vpc = mpc + (margin)% * mpc

    _receiver = Receiver(generateName());
}

Package::Package(int id, int mass, int mpc, int vpc, int margin) : 
_id(id), _mass(mass), _mpc(mpc), _vpc(vpc), _margin(margin) {}

Package::~Package(){

}

int Package::getId() const {
    return this->_id;
}

int Package::getMass() const {
    return this->_mass;
}

int Package::getMpc() const {
    return this->_mpc;
}

int Package::getVpc() const {
    return this->_vpc;
}

Receiver Package::getReceiver(){
    return this->_receiver;
}

Receiver& Package::getReceiverRef(){
    return this->_receiver;
}

// temporary debug method
void Package::debugLog(){
    using std::printf;
    Receiver& rec = this->getReceiverRef();

    printf("==========\n");
    std::cout << "Rec:  " << this->_receiver.getName() << std::endl;
    printf("ETA:   %dh\n", rec.getEta());
    printf("WT:    %dh\n", rec.getWaitTime());
    printf("DFS:   %dkm\n\n", rec.getDistance());
    printf("ID:    %d\n", this->_id);
    printf("Mass:  %d\n", this->_mass);
    printf("MPC:   %d\n", this->_mpc);
    printf("VPC:   %d\n", this->_vpc);
    printf("==========\n");
}