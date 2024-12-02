#include "Point.h"

Point::Point(double x, double y) : m_x(x), m_y(y) {}

Point operator*(const Point& obj, const double q){
    return Point(obj.m_x * q, obj.m_y * q);
}

Point operator*(const double q, const Point& obj){
    return obj * q;
}