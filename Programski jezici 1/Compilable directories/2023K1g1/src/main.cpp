#include <iostream>

#include "Vector2D.hpp"
#include "Array.hpp"

int main(void){
    Array vectors;
    Vector2D v1, v2(3), v3(4, 7);
    Vector2D vk, vp;

    vectors.append(v1);
    vectors.append(v2);
    vectors.append(v3);

    if (vectors.at(1, vk))
        vk.display();

    vp = v2 + v3;
    v3 += Vector2D(10, 10);

    vp.display();
    v3.display();


    Array vectors_tr(vectors.transform([](const Vector2D& vector){
        return Vector2D(vector.getX() * 2, vector.getY() * 2);
    }));

    std::cout << "All:" << std::endl;
    vectors.displayAll();

    std::cout << "All (transformed):" << std::endl;
    vectors_tr.displayAll();
}