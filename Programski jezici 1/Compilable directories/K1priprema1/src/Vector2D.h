#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{
private:
    double m_x;
    double m_y;

public:
    Vector2D(double x = 0, double y = 0);

    Vector2D operator+(const Vector2D& other) const;
    void operator+=(const Vector2D& other);

    double getX() const { return this->m_x; }
    double getY() const { return this->m_y; }
};

#endif