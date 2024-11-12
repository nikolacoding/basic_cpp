#include <iostream>

#include "Point.hpp"
#include "Array.hpp"

int main(){

    auto prolaziKrozNulu = [](const Point& p) -> bool {
        return !(p.getX() == 0 || p.getY() == 0);
    };

    Point p1;
    Point p2(3);
    Point p3(4, 7);
    Point p4 = p3 * 2;

    Array a;

    a.append(p1);
    a.append(p2);
    a.append(p3);
    a.append(p4);

    Array a_f = a.filter(prolaziKrozNulu);

    Point ret;
    const bool success = a_f.at(1, ret);

    if (success)
        printf("Ret: %.1lf, %.1lf\n", ret.getX(), ret.getY());
}