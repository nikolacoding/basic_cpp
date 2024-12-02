#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
private:
    double m_re;
    double m_im;

public:
    Complex(double re = 0, double im = 0);

    double getRe() const;
    double getIm() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    void operator=(const Complex& other);
    void operator=(Complex&& other);
};

#endif