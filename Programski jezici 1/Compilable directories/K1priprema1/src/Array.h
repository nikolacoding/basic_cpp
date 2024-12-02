#ifndef ARRAY_H
#define ARRAY_H

#include "Vector2D.h"

class Array{
private:
    int m_capacity;
    int m_size;
    Vector2D* m_vectors;

public:
    Array(int initCapacity = 0);
    Array(const Array& other);
    Array(Array&& other);
    ~Array();

    void operator=(const Array&) = delete;
    void operator=(Array&&) = delete;

    int getSize() const { return this->m_size; }

    void append(const Vector2D& obj);
    bool at(const int index, Vector2D& ret);
    const bool at(const int index, Vector2D& ret) const;

    Array transform(Vector2D (*f)(const Vector2D&)) const;

private:
    void realloc(int newCapacity);
};  

#endif