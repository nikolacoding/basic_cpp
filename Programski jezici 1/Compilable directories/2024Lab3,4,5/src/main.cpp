#include <iostream>

#include "Complex.hpp"
#include "Vector.hpp"
#include "Set.hpp"
int Vector::m_n = 2;

int main(void){
    Vector v1, v2, v3, v4;

    v1[0] = Complex(2, 4);
    v1[1] = Complex(1);
    v2[0] = Complex(1, 1);
    v2[1] = Complex(2, 2);
    v3[0] = Complex(6, 9);
    v3[1] = Complex(9, 6);
    v4[0] = Complex(-16, -16);
    v4[1] = Complex(-64, -64);

    Set s1, s2, s3;
    s1 += v1;
    s1 += v2;
    s2 += v3;
    s2 += v4;
    
    s3 = s1 + s2;

    std::cout << s1;
    std::cout << s2;
    std::cout << s3;
}