#include "Array.hpp"

Array::Array(int initCapacity) : 
    m_capacity(initCapacity), m_size(0), m_objects(new Object*[initCapacity]) {}

Array::Array(Array&& other){
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_objects = other.m_objects;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_objects = nullptr;
}

Array& Array::operator=(Array&& other){
    if (this != &other){
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        this->m_objects = other.m_objects;

        other.m_capacity = 0;
        other.m_size = 0;
        other.m_objects = nullptr;
    }
    return *this;
}

Array::~Array(){
    this->dispose();
}

void Array::append(Object* const obj){
    if (this->m_size == this->m_capacity)
        this->realloc(this->m_capacity * 2);
    
    this->m_objects[this->m_size++] = obj;
}

Object* Array::at(int index) const {
    if (index >= 0 && index < this->m_size)
        return this->m_objects[index];
    return nullptr;
}

void Array::dispose(){
    for (int i = 0; i < this->m_size; i++)
        delete this->m_objects[i];

    delete[] this->m_objects;
}

void Array::realloc(int newCapacity){
    std::printf("Resize: %d -> %d\n", this->m_capacity, newCapacity);
    this->m_capacity = newCapacity;

    Object** newArray = new Object*[newCapacity];
    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_objects[i];
    
    delete[] this->m_objects;
    this->m_objects = newArray;
}