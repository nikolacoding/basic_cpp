#include <iostream>

#include "Dog.h"
#include "Cat.h"
#include "Sheep.h"

#include "MyException.h"

int main(){
    Dog* dog = new Dog;
    Cat* cat = new Cat;
    Sheep* sheep = new Sheep;

    Animal* animals[] = {dog, cat, sheep};

    for (int i = 0; i < 3; i++){
        const Animal* const current = animals[i];
        current->makeSound();
        current->logInfo();
    }

    delete sheep;
    delete cat;
    delete dog;

    try{
        throw MyException("Eksepsn");
    } catch (MyException& e){
        std::cout << "Uhvacen izuzetak '" << e.what() << "'." << std::endl;
    }
}