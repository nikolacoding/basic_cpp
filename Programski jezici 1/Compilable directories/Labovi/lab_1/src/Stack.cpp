#include "Stack.h"
#include <iostream>

Stack::Stack(int initialCapacity) : capacity(initialCapacity), 
                                    topIndex(-1), 
                                    data(new Point[initialCapacity]) {}

Stack::~Stack(){
    delete[] this->data;
}

void Stack::push(Point& value){
    // lokalna lambda funkcija, moze se ovo uraditi i manuelno unutar uslova gdje se poziva
    auto upsize = [this](int oldCapacity, int newCapacity) -> void {
        this->capacity = newCapacity;
        this->resize(newCapacity);
        std::cout << "Upsized from " << oldCapacity << " to " << newCapacity << std::endl;
    };

    if (this->size() == this->capacity){
        upsize(this->capacity, this->capacity * 2);
    }

    this->data[++topIndex] = value;
}

bool Stack::pop(Point& poppedPoint){
    // smanjuje se alocirana memorija u slucaju da je velicina steka pola (ili manje) od
    // kapaciteta tj. alociranog prostora

    // lokalna lambda funkcija, moze se ovo uraditi i manuelno unutar uslova gdje se poziva
    auto downsize = [this](int oldCapacity, int newCapacity) -> void {
        this->capacity = newCapacity;
        this->resize(newCapacity);
        std::cout << "Downsized from " << oldCapacity << " to " << newCapacity << std::endl;
    };
    
    if (!this->isEmpty()){
        poppedPoint = this->data[this->topIndex--];

        int downsizeThreshold = this->capacity / 2;
        if (this->size() == downsizeThreshold){
            downsize(this->capacity, this->capacity / 2);
        }

        return true;
    }
    return false;
}

Point& Stack::top(){
    if (!this->isEmpty())
        return this->data[this->topIndex];
    
    return Point::invalidPoint;
}

bool Stack::isEmpty(){
    return !(this->size());
}

int Stack::size(){
    return this->topIndex + 1;
}

void Stack::resize(int newCapacity){
    // da se podsjetimo, realokacija mem. din. niza koristeci strogo C++ logiku ide na sljedeci nacin:
    //      1) kreiramo novi dinamicki niz velicine koja odgovara potrebama realokacije
    //      2) for petljom u njega prepisemo svaki clan starog niza
    //      3) koristeci delete[] dealociramo stari niz
    //      4) pokazivac this->data postavimo da pokazuje na pocetak novog niza

    Point* newArray = new Point[newCapacity];

    for (int i = 0; i < this->size(); i++)
        newArray[i] = this->data[i];
        // pravilno je i newArray[i] = Point(this->data[i].getX(), this->data[i].getY());

    delete[] this->data;
    this->data = newArray;
}