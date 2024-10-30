#include "Storage.h"

Storage::Storage(int maxLoss, int maxProfit, int numPackageStacks) : 
                _maxLoss(maxLoss), _maxProfit(maxProfit), _allPackages(new PackageStack[numPackageStacks])
{

}

Storage::~Storage(){

}

int Storage::getNetCurrent() const {
    return this->_netCurrent;
}

void Storage::addNetCurrent(int toAdd){
    this->_netCurrent += toAdd;
}