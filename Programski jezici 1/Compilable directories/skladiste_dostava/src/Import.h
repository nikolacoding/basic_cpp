#ifndef IMPORT_H
#define IMPORT_H

#include "Storage.h"

class Import{
private:
    const int _newPackagesPerWave;
    const int _averagePackagePrice;
    const int _packagePriceVariance;
public:
    Import(int newPackagesPerWave = 2, int averagePackagePrice = 30, int packagePriceVariance = 20);
    ~Import();

    void importNewPackages(Storage& storage);
};

#endif