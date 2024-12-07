#include <iostream>
#include <vector>

#include "Cat.h"
#include "Dog.h"

int main(){
    Animal* cat1 = new Cat(0.5, 7);
    Animal* cat2 = *cat1 * 2;
    Animal* cat3 = *cat1 + *cat2;

    Animal* dog1 = new Dog(1, 16);
    Animal* dog2 = dog1->clone();
        *dog2 *= 2;
    Animal* dog3 = dog1->clone();
        *dog3 += *dog2;

    std::vector<Animal *> animals = {cat1, cat2, cat3, dog1, dog2, dog3};
    for (const auto* const animal : animals){
        animal->sound();
        animal->logMetrics();
        delete animal;
    }
}