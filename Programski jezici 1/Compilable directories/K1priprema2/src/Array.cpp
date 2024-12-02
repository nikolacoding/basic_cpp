#include "Array.h"
#include <iostream>

Array::Array(int initCapacity) :
    m_capacity(initCapacity), m_size(0), m_points(new Point[initCapacity]) {

}

Array::Array(const Array& other) {
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_points = new Point[this->m_capacity];

    for (int i = 0; i < this->m_size; i++)
        this->m_points[i] = other.m_points[i];
}

Array::Array(Array&& other){
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_points = other.m_points;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_points = nullptr;
}

Array::~Array() {
    delete[] this->m_points;
}

void Array::append(const Point& obj){
    if (this->m_size == this->m_capacity)
        this->realloc(this->m_capacity * 2);

    this->m_points[m_size++] = obj;
}

bool Array::at(const int index, Point& ret){
    if (index < 0 || index >= this->m_size || this->m_size <= 0)
        return false;
    
    ret = this->m_points[index];
    return true;
}

const bool Array::at(const int index, Point& ret) const {
    if (index < 0 || index >= this->m_size || this->m_size <= 0)
        return false;
    
    ret = this->m_points[index];
    return true;
}

Array Array::filter(bool (*f)(const Point& current)) const {
    Array newArray;

    for (int i = 0; i < this->m_size; i++){
        Point current;
        if (this->at(i, current) && (*f)(current))
            newArray.append(current);
    }

    return newArray;
}

void Array::realloc(int newCapacity){
    if (this->m_capacity == 0){
        this->m_points = new Point[1];
        this->m_capacity = 1;
        return;
    }
    this->m_capacity = newCapacity;
    Point* newArray = new Point[newCapacity];
    
    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_points[i];
    
    delete[] this->m_points;
    this->m_points = newArray;
}