#include <iostream>

#include "Complex.h"
#include "Array.h"

int main(void){
    Complex z1(1, 1), z2(2, 2), z3(3, 0), z4(0, 4);

    Array a1;
    a1.append(z1); a1.append(z2); a1.append(z3); a1.append(z4);

    Array a2 = a1.transform([](Complex current){
        return Complex(current.getRe() * 2, current.getIm() * 2);
    });

    std::cout << a1 << std::endl;
    std::cout << a2;
}