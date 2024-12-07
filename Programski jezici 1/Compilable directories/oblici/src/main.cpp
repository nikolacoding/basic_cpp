#include <iostream>

#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

int main(){
    
    // P = 4, O = 8
    Square* sq = new Square(2);

    // P = 6, O = 10
    Rectangle* rec = new Rectangle(2, 3);

    // P = 3.14, O = 6.28
    Circle* circ = new Circle(1);

    // polimorfni dinamicki niz
    Shape2D* shapes[] = {sq, rec, circ};

    for (int i = 0; i < 3; i++){
        // skaliranje bez bocnog efekta
        const Shape2D* const current = *shapes[i] * 2;
        const char* const current_type = current->type();
        const double current_p = current->getArea();
        const double current_o = current->getPer();
        std::printf("%s: P: %.2lf, O: %.2lf\n",
                    current_type, current_p, current_o);
    }

    delete circ; 
    delete rec;
    delete sq;
}