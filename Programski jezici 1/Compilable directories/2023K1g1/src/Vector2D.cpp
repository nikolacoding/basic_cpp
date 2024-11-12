#include "Vector2D.hpp"

Vector2D Vector2D::invalidVector = Vector2D(-999, -999);

Vector2D::Vector2D(double x, double y) : m_x(x), m_y(y) {

}

double Vector2D::getX() const {
    return this->m_x;
}

double Vector2D::getY() const {
    return this->m_y;
}

void Vector2D::setX(double val){
    this->m_x = val;
}

void Vector2D::setY(double val){
    this->m_y = val;
}

Vector2D Vector2D::operator+(const Vector2D& other){
    double x = this->getX() + other.getX();
    double y = this->getY() + other.getY();

    return Vector2D(x, y);
}