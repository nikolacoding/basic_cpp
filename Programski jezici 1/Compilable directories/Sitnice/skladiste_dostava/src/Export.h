#ifndef EXPORT_H
#define EXPORT_H

#include <string>
#include <vector>
#include "Package.h"

class Export{
private:
    const std::string _name;
    int _currentLoad;
    int _maxCapacity;
    int _maxSpeed;
    std::vector<Package> loadedPackages;
public:
    Export(std::string name = "UnnamedDeliveryGuy");
    ~Export();

    std::string getName() const;
    int getMaxCapacity() const;
    int getCurrentLoad() const;
    int getMaxSpeed() const;

    int addToLoad(Package p);
    int removeFromLoad(Package p);
};

#endif