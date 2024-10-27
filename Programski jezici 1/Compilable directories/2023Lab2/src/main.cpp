#include <iostream>
#include "Array.h"
using PJ1Lab::Array;

#define INIT 5

// napomena: realokacija nije uradjena

int main(void)
{
    Array array(INIT);

    for (int i = 0; i < INIT; i++){
        array.append(i * 2);
    }

    array.insertAt(INIT - 1, 77.5);
    array.removeAt(INIT - 3);

    bool check;
    double v = array.at(INIT - 3, check);
    std::cout << "V: ";
    if (check) std::cout << v;
    else std::cout << "invalid";
    std::cout << std::endl;

    array.at(INIT - 1);
}   