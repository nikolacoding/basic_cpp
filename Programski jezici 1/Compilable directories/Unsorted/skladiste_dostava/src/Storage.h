#ifndef STORAGE_H
#define STORAGE_H

#include "PackageStack.h"
#include "Stats.h"

class Storage{
private:
    const int _maxLoss;
    const int _maxProfit;
    PackageStack* _allPackages;
    int _netCurrent;
    // stats needs some insight into these variables, so it's been labelled as a friend
    friend class Stats;

public:
    Storage(int maxLoss = -5000, int maxProfit = 5000, int numPackageStacks = 2);
    ~Storage();

    int getNetCurrent() const;
    void addNetCurrent(int toAdd);
};

#endif