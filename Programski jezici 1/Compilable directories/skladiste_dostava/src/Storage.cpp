#include "Storage.h"

Storage::Storage(int maxLoss, int maxProfit, int numPackageStacks) : 
                _numPackageStacks(numPackageStacks),
                _packageStacks(new PackageStack[numPackageStacks]),
                _maxLoss(maxLoss), 
                _maxProfit(maxProfit)
{

}

Storage::~Storage(){
    delete[] this->_packageStacks;
}

int Storage::getNumStacks() const {
    return this->_numPackageStacks;
}

PackageStack Storage::getNthStack(const int n) const {
    return this->_packageStacks[n];
}

int Storage::getNetCurrent() const {
    return this->_netCurrent;
}

void Storage::addNetCurrent(const int toAdd){
    this->_netCurrent += toAdd;
}