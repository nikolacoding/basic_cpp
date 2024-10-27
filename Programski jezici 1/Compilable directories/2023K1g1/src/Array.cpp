#include "Array.h"
#include <iostream>

Array::Array() : capacity(2), size(0), vectors(new Vector2D[capacity]) {
    // konstruktor
}

Array::~Array(){
    delete[] this->vectors;
}

void Array::append(Vector2D object){
    if (this->size >= this->capacity){
        this->capacity *= 2;
    }
    this->vectors[this->size++] = object;
}