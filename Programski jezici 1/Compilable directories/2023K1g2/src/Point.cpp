#include "Point.hpp"

Point::Point(double x, double y) : m_x(x), m_y(y) {
    
}

Point Point::operator*(int multiplier){
    return Point(this->getX() * multiplier, this->getY() * multiplier);
}

double Point::getX() const {
    return this->m_x;
}

double Point::getY() const {
    return this->m_y;
}