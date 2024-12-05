#include "Animal.h"

class Cat : public Animal{
public:
    Cat();
    virtual void makeSound() const override;
};