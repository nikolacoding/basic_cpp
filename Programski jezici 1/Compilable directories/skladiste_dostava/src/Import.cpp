#include "Import.h"

Import::Import(int newPackagesPerWave, int averagePackagePrice, int packagePriceVariance) : 
            _newPackagesPerWave(newPackagesPerWave), 
            _averagePackagePrice(averagePackagePrice),
            _packagePriceVariance(packagePriceVariance)
{

}

Import::~Import(){

}

void Import::importNewPackages(Storage& storage){
    // logika uvoza novog talasa paketa

    for (int i = 0; i < storage.getNumStacks(); i++){
        Package p;
        storage.getNthStack(i).push(p);
    }
}