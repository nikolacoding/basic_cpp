#include "Rectangle.h"

const char* Rectangle::type() const {
    return "rectangle";
}

double Rectangle::getArea() const {
    return this->m_a * this->m_b;
}

double Rectangle::getPer() const {
    return (this->m_a * 2 + this->m_b * 2);
}

void Rectangle::scaleInPlace(const double q){
    this->m_a *= q;
    this->m_b *= q;
}

Shape2D* Rectangle::clone() const {
    return new Rectangle(*this);
}