#include "Complex.hpp"
#include "Array.hpp"

int main(void){
    Complex z1(5, 5);
    Complex z2(-5, 6);
    Complex z3 = z1 + z2;
    
    Array arr;

    arr.append(z1);
    arr.append(z2);
    arr.append(z3);

    Array arrTr = arr.transform([](Complex current){
        return Complex(current.getRe() * 2, current.getIm() * 2);
    });

    std::cout << arr;
    std::cout << arrTr;
}