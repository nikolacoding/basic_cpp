#include "Animal.h"

class Dog : public Animal{
public:
    Dog();
    virtual void makeSound() const override;
};