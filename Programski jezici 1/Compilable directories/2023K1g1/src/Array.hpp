#ifndef ARRAY_H
#define ARRAY_H

#include "Vector2D.hpp"
#include <iostream>

class Array{
private:
    int m_capacity;
    int m_size;
    Vector2D* m_array;

private:
    void realloc(const int newCapacity);
    Array& operator=(const Array& other) = delete;

public:
    Array(int initCapacity = 1);
    Array(const Array& other);
    //~Array();

    int getSize() const;

    void append(const Vector2D& vector);

    Vector2D& at(const int index, bool& success);
    const Vector2D& at(const int index, bool& success) const;

    void displayAll();
};

#endif