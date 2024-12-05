#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal{
protected:
    int m_age;
    double m_mass;

public:
    Animal();
    virtual void makeSound() const = 0;
    virtual void logInfo() const;
};

#endif