#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) : m_x(x), m_y(y){

}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(this->m_x + other.m_x, this->m_y + other.m_y);
}

void Vector2D::operator+=(const Vector2D& other) {
    this->m_x += other.m_x; 
    this->m_y += other.m_y;
}