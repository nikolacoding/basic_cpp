#include <iostream>

#include "Vector2D.h"
#include "Array.h"

Vector2D Vector2D::errorVector(-999, -999);

int main(void){
    // v0 - podrazumijevani/default konstruktor
    // v[1, 5] - parametrizovani konstruktor
    // v6 - operator mnozenja
    Vector2D v0, v1(1, 1), v2(2, 2), v3(3, 3), v4(4, 4), v5(5, 5), v6 = v1 * v3;

    Array a;

    a.append(v0); a.append(v1); a.append(v2); a.append(v3); a.append(v4); a.append(v5); a.append(v6); 

    Array b(a); // konstruktor kopije niza (duboka kopija)

    // Array c; c = a;
    // ^ greska, onemogucena dodjela

    bool s;
    double outofboundsX = b.at(77, s).getX();
    if (s)
        std::cout << "out of bounds: " <<outofboundsX << std::endl;

    double inboundsX = b.at(2, s).getX();
    if (s)
        std::cout << "within bounds: " << inboundsX << std::endl;

    // ^ "at" metoda i signalizacija greske

    // ispod pretpostavljamo da necemo indeksirati van granica niza
    for (int i = 0; i < 6; i++){
        Vector2D& current = b.at(i, s);
        const double x = current.getX();
        const double y = current.getY();

        std::cout << "(" << x << ", " << y << ")" << std::endl; 
    }
}