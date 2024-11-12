#include "Array.hpp"

void Array::realloc(const int newCapacity){
    std::printf("Upsizing from %d to %d\n", this->m_capacity, newCapacity);
    this->m_capacity = newCapacity;
    Point* newArray = new Point[newCapacity];
    for (int i = 0; i < this->m_capacity; i++){
        newArray[i] = this->m_array[i];
    }
    delete[] this->m_array;
    this->m_array = newArray;
}

bool Array::isFull(){
    return this->m_size == this->m_capacity;
}

Array::Array(int initCapacity) : 
m_capacity(initCapacity), m_size(0), m_array(new Point[initCapacity]) { }

// konstruktor (duboke) kopije
Array::Array(const Array& other){
    if (this != &other){
        delete[] this->m_array;
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        this->m_array = new Point[this->m_capacity];

        for (int i = 0; i < other.m_size; i++){
            this->m_array[i] = other.m_array[i];
        }
    }
}

Array::~Array(){
    delete[] this->m_array;
}

void Array::append(const Point& newPoint){
    if (this->isFull())
        realloc(this->m_capacity * 2);

    this->m_array[this->m_size++] = newPoint;
}

bool Array::at(const int index, Point& element){
    if (index >= this->m_size)
        return false;
    
    element = this->m_array[index];
    return true;
}

const bool Array::at(const int index, Point& element) const {
    if (index >= this->m_size)
        return false;
    
    element = this->m_array[index];
    return true;
}

Array Array::filter(bool (*f)(const Point& p)){
    Array newArray;
    for (int i = 0; i < this->m_size; i++){
        const Point& current = this->m_array[i];
        if ((*f)(current)){
            newArray.append(current);
        }
    }

    return newArray;
}