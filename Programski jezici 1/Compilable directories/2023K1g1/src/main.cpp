#include <iostream>
#include "Vector2D.hpp"
#include "Array.hpp"

int main(void){
    auto dbl = [](Vector2D& p) -> void {
        p.setX(p.getX() * 2);
        p.setY(p.getY() * 2);
    };

    Vector2D v1(2, 4);
    Vector2D v2(10, 20);
    Vector2D v3(12, 15);

    Array a;

    a.append(v1);
    a.append(v2);
    a.append(v3);

    a.displayAll();

    Array b(a.transform(dbl));

    b.displayAll();
}