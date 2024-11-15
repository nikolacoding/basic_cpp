#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D{
private:
    double m_x;
    double m_y;

public:
    Vector2D(double x = 0.0, double y = 0.0);

    double getX() const;
    double getY() const;
    void display() const;

    Vector2D operator+(const Vector2D& other) const;
    void operator+=(const Vector2D& other);
};

#endif