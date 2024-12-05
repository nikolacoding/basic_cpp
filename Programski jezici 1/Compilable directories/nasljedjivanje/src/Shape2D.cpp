#include "Shape2D.h"

Shape2D* Shape2D::operator*(const double quotient) {
    return this->rescale(quotient);
}