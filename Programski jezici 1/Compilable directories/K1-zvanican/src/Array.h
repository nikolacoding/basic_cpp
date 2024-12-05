#ifndef ARRAY_H
#define ARRAY_H

#include "Vector2D.h"

class Array{
private:
    int m_capacity;
    int m_size;
    Vector2D* m_vectors;

public:
    Array(int initCapacity = 1);
    Array(const Array& other);
    Array(Array&& other);
    ~Array();
    Array& operator=(const Array&) = delete;
    Array& operator=(Array&&) = delete;

    void append(const Vector2D& obj);
    Vector2D& at(int index, bool& success);

private:
    void realloc(int newCapacity);
};

#endif