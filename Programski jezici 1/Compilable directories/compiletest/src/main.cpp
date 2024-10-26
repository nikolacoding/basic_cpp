#include <iostream>
#include "IntArray.h"

int main(void)
{
    IntArray array;
    
    for (int i = 0; i < 15; i++){
        if (!array.append(i * 2))
            std::cout << "Array is already at maximum (" << array.maxSize << ") elements, ignoring" << 
            "the addition of " << i * 2 << std::endl;
    }

    array.writeAll();

    std::cout << "Jedan po jedan: ";
    for (int i = 0; i < array.maxSize; i++){
        int v = array.pop();
        std::cout << v << " ";
    }
    std::cout << std::endl;
    array.writeAll();
    std::cout << std::endl;
    return 0;
}