#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D{
private:
    float m_x;
    float m_y;

public:
    Vector2D(float x = 0, float y = 0);
    static Vector2D invalidVector;
    
    float getX() const;
    float getY() const;
    bool equals(const Vector2D& other) const;
    void print() const;

    void operator+=(Vector2D& other);               // dodatno
    Vector2D operator+(Vector2D& other) const;      // dodatno

    void operator*=(float v);

    void addInPlace(const Vector2D& other);
    Vector2D add(const Vector2D& other) const;
};

#endif