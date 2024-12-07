#include "Circle.h"

constexpr double _PI = 3.141;

const char* Circle::type() const {
    return "circle";
}

double Circle::getArea() const {
    return this->m_radius * this->m_radius * _PI;
}

double Circle::getPer() const {
    return 2 * this->m_radius * _PI;
}

void Circle::scaleInPlace(const double q) {
    this->m_radius *= q;
}

Shape2D* Circle::clone() const {
    return new Circle(*this);
}