#ifndef POINT_H
#define POINT_H

class Point{
private:
    double m_x;
    double m_y;
public:
    Point(double x = 0.0, double y = 0.0);

    double getX() const;
    double getY() const;

    Point operator*(int multiplier);
};

#endif