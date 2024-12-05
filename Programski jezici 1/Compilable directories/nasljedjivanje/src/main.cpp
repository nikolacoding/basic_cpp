#include <iostream>

#include "Square.h"

int main(void){
    Square s1(5);
    Square *s2 = s1 * 2;
    std::cout << s1.getArea();
    std::cout << s2->getArea();
}