#ifndef EXPORT_H
#define EXPORT_H

#include <string>

class Export{
private:
    const std::string _name;
    int _maxCapacity;
    int _maxSpeed;
public:
    Export(std::string name = "UnnamedDeliveryGuy");
    ~Export();

    std::string getName() const;
    int getMaxCapacity() const;
    int getMaxSpeed() const;
};

#endif