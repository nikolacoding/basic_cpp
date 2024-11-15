#ifndef ARRAY_H
#define ARRAY_H

#include "Vector2D.hpp"

class Array{
private:
    int m_capacity;
    int m_size;
    Vector2D* m_array;

private:
    void realloc(const int newCapacity);
    inline bool isFull();
    Array& operator=(const Array& other) = delete;

public:
    Array(int initCapacity = 1);
    Array(const Array& other);
    ~Array();

    void displayAll();

    void append(const Vector2D& vector);
    bool at(const int index, Vector2D& member);
    const bool at(const int index, Vector2D& member) const;

    Array transform(Vector2D (*f)(const Vector2D& vector)) const;
};

#endif