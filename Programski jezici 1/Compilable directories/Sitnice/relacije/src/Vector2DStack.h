#ifndef VECTOR2DSTACK_H
#define VECTOR2DSTACK_H

#include "Vector2D.h"
#include "Vector2DArray.h"

class Vector2DStack{
private:
    Vector2DArray m_stackArray;

public:
    Vector2DStack();
    void push(const Vector2D& vector);
    bool pop(Vector2D& ret);
};

#endif