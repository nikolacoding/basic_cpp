#ifndef STORAGE_H
#define STORAGE_H

#include "PackageStack.h"

class Storage{
private:
    const int _numPackageStacks;
    PackageStack* _packageStacks;
    
    const int _maxLoss;
    const int _maxProfit;
    int _netCurrent;
    // Stats.h needs some insight into these variables, so it's been labelled as a friend
    friend class Stats;

public:
    Storage(int maxLoss = -5000, int maxProfit = 5000, int numPackageStacks = 2);
    ~Storage();

    int getNumStacks() const;
    PackageStack getNthStack(const int n) const;

    int getNetCurrent() const;
    void addNetCurrent(const int toAdd);
};

#endif