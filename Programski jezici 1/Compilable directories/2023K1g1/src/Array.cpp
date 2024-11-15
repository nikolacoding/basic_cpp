#include <iostream>
#include "Array.hpp"

void Array::realloc(const int newCapacity){
    std::printf("Upscaling from %d to %d.\n", this->m_capacity, newCapacity);
    Vector2D* newArray = new Vector2D[newCapacity];
    this->m_capacity = newCapacity;

    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_array[i];

    delete[] this->m_array;
    this->m_array = newArray;
}

inline bool Array::isFull(){
    return this->m_size == this->m_capacity;
}

Array::Array(int initCapacity) : 
    m_capacity(initCapacity), m_size(0), m_array(new Vector2D[initCapacity]){

}

Array::Array(const Array& other) : 
    m_size(other.m_size), m_capacity(other.m_capacity), m_array(new Vector2D[other.m_capacity]) {

    for (int i = 0; i < other.m_size; i++)
        this->m_array[i] = other.m_array[i];
}

Array::~Array() {
    delete[] m_array;
    std::printf("Deallocated %d x sizeof(Vector2D).\n", this->m_capacity);
}

void Array::displayAll(){
    for (int i = 0; i < this->m_size; i++)
        printf("(%.1lf, %.1lf)\n", this->m_array[i].getX(), this->m_array[i].getY());
}

void Array::append(const Vector2D& vector){
    if (this->isFull())
        this->realloc(m_capacity * 2);

    this->m_array[this->m_size++] = vector;
}

bool Array::at(const int index, Vector2D& member){
    if (index >= this->m_size)
        return false;
    
    member = this->m_array[index];
    return true;
}

const bool Array::at(const int index, Vector2D& member) const {
    if (index >= this->m_size)
    return false;
    
    member = this->m_array[index];
    return true;
}

// 6.1.
Array Array::transform(Vector2D (*f)(const Vector2D& vector)) const {
    Array newArray(this->m_capacity);

    for (int i = 0; i < this->m_size; i++)
        newArray.append((*f)(this->m_array[i]));

    return newArray;
}