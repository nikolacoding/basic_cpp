#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{
private:
    double m_x;
    double m_y;

public:
    Vector2D(double x = 0, double y = 0);
    static Vector2D invalidVector;

    double getX() const;
    double getY() const;

    void setX(double val);
    void setY(double val);

    Vector2D operator+(const Vector2D& other);
};

#endif