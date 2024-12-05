#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

class Sheep : public Animal{
public:
    Sheep();
    virtual void makeSound() const override;
};

#endif