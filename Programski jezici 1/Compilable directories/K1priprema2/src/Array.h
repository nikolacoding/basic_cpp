#ifndef ARRAY_H
#define ARRAY_H

#include "Point.h"

class Array{
private:
    int m_capacity;
    int m_size;
    Point* m_points;

public:
    Array(int initCapacity = 0);
    Array(const Array& other);
    Array(Array&& other);
    ~Array();
    void operator=(const Array& other) = delete;
    void operator=(Array&& other) = delete;

    int getSize() const { return this->m_size; }

    void append(const Point& obj);
    bool at(const int index, Point& ret);
    const bool at(const int index, Point& ret) const;

    Array filter(bool (*f)(const Point& current)) const;

private:
    void realloc(int newCapacity);
};

#endif