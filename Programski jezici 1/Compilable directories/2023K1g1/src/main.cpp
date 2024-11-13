#include <iostream>
#include "Vector2D.hpp"
#include "Array.hpp"

static Array transform(const Array& array, Vector2D (*f)(const Vector2D&)){
    Array newArray;
    for (int i = 0; i < array.getSize(); i++){
        bool success;
        const Vector2D& current = array.at(i, success);
        newArray.append((*f)(current));
    }
    return newArray;
}

int main(void){

    Vector2D v1(2, 4);
    Vector2D v2(10, 20);
    Vector2D v3(12, 15);

    Array a;

    a.append(v1);
    a.append(v2);
    a.append(v3);

    a.displayAll();

    Array b(transform(a, [](const Vector2D& vector){
        Vector2D newVector;
        newVector.setX(vector.getX() * 2);
        newVector.setY(vector.getY() * 2);
        return newVector;
    }));

    b.displayAll();
}