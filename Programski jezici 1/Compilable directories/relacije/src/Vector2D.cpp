#include "Vector2D.h"

Vector2D Vector2D::invalidVector = Vector2D(-999, -999);

Vector2D::Vector2D(float x, float y) : m_x(x), m_y(y) {

}

float Vector2D::getX() const {
    return this->m_x;
}

float Vector2D::getY() const {
    return this->m_y;
}

bool Vector2D::equals(const Vector2D& other) const {
    return this->getX() == other.getX() && this->getY() == other.getY();
}

void Vector2D::print() const {
    std::cout << "x: " << this->getX() << " y: " << this->getY() << std::endl;
}

void Vector2D::addInPlace(const Vector2D& other){
    this->m_x += other.getX();
    this->m_y += other.getY();
}

Vector2D Vector2D::add(const Vector2D& other) const {
    Vector2D ret = Vector2D(this->getX() + other.getX(), this->getY() + other.getY());
    return ret;
}

void Vector2D::operator+=(Vector2D& other){
    this->addInPlace(other);
}

Vector2D Vector2D::operator+(Vector2D& other) const {
    Vector2D ret = Vector2D(this->getX() + other.getX(), this->getY() + other.getY());
    return ret;
}

void Vector2D::operator*=(float v){
    this->m_x *= v;
    this->m_y *= v;
}