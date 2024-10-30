#include "Import.h"

Import::Import(int newPackagesPerWave = 2, int averagePackagePrice = 30, int packagePriceVariance = 20) : 
            _newPackagesPerWave(newPackagesPerWave), 
            _averagePackagePrice(averagePackagePrice),
            _packagePriceVariance(packagePriceVariance)
{

}

Import::~Import(){

}

void Import::importNewPackages(){
    // logika uvoza novog talasa paketa
}