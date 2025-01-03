#include "Vector2D.h"
Vector2D::Vector2D() : m_x(0), m_y(0) { }
Vector2D::Vector2D(double x, double y) : m_x(x), m_y(y){ }

double Vector2D::operator*(const Vector2D& other) const {
    return (this->m_x * other.m_x + this->m_y * other.m_y);
}