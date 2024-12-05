#include "Array.h"

#include <iostream> // debug

Array::Array(int initCapacity) :
    m_capacity(initCapacity), m_size(0), m_vectors(new Vector2D[initCapacity]){
    
}

// cc
Array::Array(const Array& other){
    // std::cout << "cc" << std::endl;

    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_vectors = new Vector2D[other.m_capacity];

    for (int i = 0; i < other.m_size; i++)
        this->m_vectors[i] = other.m_vectors[i];
}

// mc
Array::Array(Array&& other){
    // std::cout << "mc" << std::endl;

    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_vectors = other.m_vectors;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_vectors = nullptr;
}

Array::~Array(){
    delete[] this->m_vectors;
}

void Array::append(const Vector2D& obj){
    if (this->m_size == this->m_capacity)
        this->realloc(this->m_capacity * 2);

    this->m_vectors[this->m_size++] = obj;
}

Vector2D& Array::at(int index, bool& success){
    if (index < 0 || index >= this->m_size || this->m_size == 0){
        success = false;
        return Vector2D::errorVector;
    }
    success = true;
    return this->m_vectors[index];
}

void Array::realloc(int newCapacity){
    if (newCapacity < 0)
        newCapacity = 0;
    
    // std::printf("realloc: %d -> %d\n", this->m_capacity, newCapacity);
    this->m_capacity = newCapacity;
    Vector2D* newArray = new Vector2D[newCapacity];

    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_vectors[i];
    
    delete[] this->m_vectors;
    this->m_vectors = newArray;
}