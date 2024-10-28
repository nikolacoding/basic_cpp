#include <iostream>
#include "Complex.h"
#include "Utility.h"

int main(){
    Complex z1(4);      // (4, 0)
    Complex z2;         // (0, 0)
    Complex z3(5, 3);   // (5, 3)
    Complex z4;         // (0, 0)
    Complex z5(0, 5);   // (0, 6)

    z2 = z1 + z3;       // z2 = (4, 0) + (5, 3) = (9, 3)
    z4 = z2;            // z4 = (9, 3)

    Utility::factorial(z4.getReRef(), z4.getImRef()); // z4 = (362880, 6);
    Utility::factorial(z5.getImRef());

    z1.write();
    z2.write();
    z3.write();
    z4.write();
    z5.write();
}