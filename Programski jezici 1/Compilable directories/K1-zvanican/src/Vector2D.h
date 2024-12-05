#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{
private:
    double m_x;
    double m_y;

public:
    Vector2D();
    Vector2D(double x, double y = 0.0);
    static Vector2D errorVector;

    double getX() const { return this->m_x; }
    double getY() const { return this->m_y; }

    void setX(double val) { this->m_x = val; }
    void setY(double val) { this->m_y = val; }

    double operator*(const Vector2D& other) const;
};
#endif