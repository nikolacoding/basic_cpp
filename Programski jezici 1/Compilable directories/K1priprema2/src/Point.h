#ifndef POINT_H
#define POINT_H

class Point{
private:
    double m_x;
    double m_y;

public:
    Point(double x = 0, double y = 0);

    friend Point operator*(const Point& obj, const double q);
    friend Point operator*(const double q, const Point& obj);

    double getX() const { return this->m_x; }
    double getY() const { return this->m_y; }
};

#endif