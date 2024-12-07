#include "Square.h"

const char* Square::type() const {
    return "square";
}

double Square::getArea() const {
    return this->m_side * this->m_side;
}

double Square::getPer() const {
    return 4 * this->m_side;
}

void Square::scaleInPlace(const double q){
    this->m_side *= q;
}

Shape2D* Square::clone() const {
    return new Square(*this);
}