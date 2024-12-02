#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
private:
    double m_re;
    double m_im;

public:
    Complex(double re = 0, double im = 0);

    double getRe() const { return this->m_re; }
    double getIm() const { return this->m_im; }

    Complex operator+(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& stream, const Complex& obj);
};

#endif