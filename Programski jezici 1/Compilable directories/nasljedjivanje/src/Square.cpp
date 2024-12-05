#include "Square.h"

const char* Square::type() const {
    return "Square";
}

inline double Square::getArea() const {
    return this->m_side * this->m_side;
}

inline double Square::getCircum() const {
    return 4 * this->m_side;
}

Square* Square::clone() const {
    return new Square(*this);
}

Square* Square::rescale(const double quotient){
    Square* scaled = new Square(this->m_side * quotient);
    return scaled;
}