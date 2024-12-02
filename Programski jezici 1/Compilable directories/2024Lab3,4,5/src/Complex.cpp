#include "Complex.hpp"

Complex::Complex(double re, double im) : m_re(re), m_im(im) { }

double Complex::getRe() const {
    return this->m_re;
}

double Complex::getIm() const {
    return this->m_im;
}

bool Complex::operator==(const Complex& other) const {
    return ((this->getRe() == other.getRe()) && (this->getIm() == other.getIm()));
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

void Complex::operator=(const Complex& other){
    this->m_re = other.m_re;
    this->m_im = other.m_im;
}

void Complex::operator=(Complex&& other){
    this->m_re = other.m_re;
    this->m_im = other.m_im;
}