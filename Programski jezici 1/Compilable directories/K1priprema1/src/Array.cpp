#include "Array.h"

Array::Array(int initCapacity) : 
    m_capacity(initCapacity), m_size(0), m_vectors(new Vector2D[initCapacity]){

}

Array::Array(const Array& other){
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_vectors = new Vector2D[other.m_capacity];
    for (int i = 0; i < other.m_size; i++)
        this->m_vectors[i] = other.m_vectors[i];
}

Array::Array(Array&& other){
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_vectors = other.m_vectors;

    other.m_size = 0;
    other.m_capacity = 0;
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

bool Array::at(const int index, Vector2D& ret){
    if (index < 0 || index >= this->m_size || this->m_size == 0)
        return false;

    ret = this->m_vectors[index];
    return true;
}

const bool Array::at(const int index, Vector2D& ret) const {
    if (index < 0 || index >= this->m_size || this->m_size == 0)
        return false;

    ret = this->m_vectors[index];
    return true;
}

Array Array::transform(Vector2D (*f)(const Vector2D&)) const {
    Array newArray;

    for (int i = 0; i < this->m_size; i++)
        newArray.append((*f)(this->m_vectors[i]));
    
    return newArray;
}

void Array::realloc(int newCapacity){
    if (this->m_capacity == 0){
        this->m_capacity = 1;
        this->m_vectors = new Vector2D[1];
        return;
    }
    this->m_capacity = newCapacity;
    Vector2D* newArray = new Vector2D[newCapacity];

    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_vectors[i];

    delete[] this->m_vectors;
    this->m_vectors = newArray;
}