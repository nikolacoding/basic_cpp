#ifndef ARRAY_H
#define ARRAY_H

#include "Point.hpp"
#include <iostream>

class Array{
private:
    int m_capacity;
    int m_size;
    Point* m_array;

private:
    void realloc(const int newCapacity);
    bool isFull();
    Array& operator=(const Array&) = delete;

public:
    Array(int initCapacity = 1);
    Array(const Array& other);
    ~Array();

    void append(const Point& newPoint);

    bool at(const int index, Point& element);
    const bool at(const int index, Point& element) const;

    Array filter(bool (*f)(const Point& p));
};

#endif