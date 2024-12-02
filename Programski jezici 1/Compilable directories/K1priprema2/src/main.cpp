#include <iostream>

#include "Point.h"
#include "Array.h"

int main(){
    Point p1(1, 1), p2 = p1 * 2, p3 = 3 * p1, p4(4, 5);
    Array a1;

    a1.append(p1); a1.append(p2); a1.append(p3); a1.append(p4);
    Array a2 = a1.filter([](const Point& current){
        return current.getX() != current.getY();
    });

    for (int i = 0; i < a1.getSize(); i++){
        Point current;
        a1.at(i, current);

        std::cout << current.getX() << " " << current.getY() << std::endl;
    }

    std::cout << std::endl << std::endl;

    for (int i = 0; i < a2.getSize(); i++){
        Point current;
        a2.at(i, current);

        std::cout << current.getX() << " " << current.getY() << std::endl;
    }
}