#ifndef VECTOR2DARRAY_H
#define VECTOR2DARRAY_H

#include "Vector2D.h"
#include <cstdio>

class Vector2DArray{
private:
    int m_capacity;
    int m_size;
    Vector2D* m_vectors;

public:
    Vector2DArray(int capacity = 5);
    ~Vector2DArray();

    int getCapacity() const;
    int getSize() const;

    void append(const Vector2D& vector);
    void remove(int index);
    Vector2D& at(int index, bool& success);
    const Vector2D& at(int index, bool& success) const;
    void forEach(void (*f)(Vector2D&));
    void forEach(void (*f)(const Vector2D&)) const;

    // pomocne funkcije
    bool isValidIndex(int index) const;
    void realloc(bool up);
    void realloc(int newCapacity);
};

#endif