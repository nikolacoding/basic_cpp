#include "Shape2D.h"

Shape2D* Shape2D::operator*(const double q) const {
    return this->scale(q);
}

void Shape2D::operator*=(const double q){
    this->scaleInPlace(q);
}

Shape2D* Shape2D::scale(const double q) const {
    Shape2D* newObj = this->clone();
    newObj->scaleInPlace(q);
    return newObj;
}