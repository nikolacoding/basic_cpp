#include "Complex.hpp"

Complex::Complex(double re, double im) : m_re(re), m_im(im) {
    
}

Complex Complex::operator+(const Complex& other) const {
    Complex ret(this->getRe() + other.getRe(), this->getIm() + other.getIm());
    return ret;
}

std::ostream& operator<<(std::ostream& stream, const Complex& obj){
    const double re = obj.getRe();
    const double im = obj.getIm();

    if (re != 0){
        stream << re;

        if (im != 0){
            if (im > 0)
                stream << " + ";
            else 
                stream << " - ";
        }
    }

    if (im != 0)
        stream << "i" << im;
    
    return stream;
}