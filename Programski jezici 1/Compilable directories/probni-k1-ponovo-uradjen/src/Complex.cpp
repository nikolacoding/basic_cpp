#include "Array.h"

Complex::Complex(double re, double im) : m_re(re), m_im(im){
    
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(this->getRe() + other.getRe(), this->getIm() + other.getIm());
}

std::ostream& operator<<(std::ostream& stream, const Complex& obj){
    const double re = obj.getRe();
    const double im = obj.getIm();

    if (re == 0 && im == 0)
        stream << "0";
    else{
        if (re != 0)
            stream << re;
        
        if (im != 0){
            if (re != 0){
                if (im > 0)
                    stream << " + ";
                else
                    stream << " - ";
            }
            stream << "i" << im;
        }
    }
    stream << std::endl;
    return stream;
}