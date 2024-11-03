#include "Complex.h"
#include <iostream>

int Complex::count = 0;

Complex operator+(Complex a, Complex b){
    return Complex(a.Re + b.Re, a.Im + b.Im);
}

Complex::Complex(int aRe, int aIm) : Re(aRe), Im(aIm) {
    count++;
    this->id = count;
}

Complex::~Complex(){
    count--;
}

void Complex::write() const {
    using std::cout;
    using std::endl;

    // brzinska implementacija
    cout << "z" << this->id << ": ";
    if (this->Re){
        cout << this->Re;
        if (this->Im)
            cout << " + " << this->Im << "i";
    }
    else if (this->Im)
        cout << this->Im << "i";
    
    cout << endl;
}

int& Complex::getReRef(){
    return this->Re;
}

int& Complex::getImRef(){
    return this->Im;
}