#include <iostream>
#include "Vector2D.h"
#include "Array.h"

int main(){
    Array a1;
    Vector2D v1(2, 2), v2(3, 3), v3(4, 4), v4(5, 5);

    a1.append(v1); a1.append(v2); a1.append(v3); a1.append(v4);

    Array a2 = a1.transform([](const Vector2D& current){
        return Vector2D(current.getX() * 2, current.getY() * 2);
    });

    for (int i = 0; i < a2.getSize(); i++){
        Vector2D current;
        a2.at(i, current);
        std::cout << current.getX() << " " << current.getY() << std::endl;
    }
}