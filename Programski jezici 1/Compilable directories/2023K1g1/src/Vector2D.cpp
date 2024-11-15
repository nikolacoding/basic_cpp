#include "Vector2D.hpp"

Vector2D::Vector2D(double x, double y) : m_x(x), m_y(y) {

}

double Vector2D::getX() const {
    return this->m_x;
}

double Vector2D::getY() const {
    return this->m_y;
}

void Vector2D::display() const {
    std::printf("> (%.1lf, %.1lf)\n", this->m_x, this->m_y);
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    Vector2D newVector(this->getX() + other.getX(), this->getY() + other.getY());
    return newVector;
}

void Vector2D::operator+=(const Vector2D& other){
    this->m_x = this->m_x + other.m_x;
    this->m_y = this->m_y + other.m_y;
}