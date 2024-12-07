#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog final : public Animal{
public:
    Dog(double height = 1, double weight = 1) : Animal(height, weight) {};
    virtual Animal* clone() const override;
    virtual void sound() const override;
    virtual void scale(const double q) override;
    virtual void add(const Animal& other) override;
};

#endif