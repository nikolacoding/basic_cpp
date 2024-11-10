#include <iostream>
#include <cstdio>
#include "Vector2D.h"
#include "Vector2DArray.h"

// random change to test upstream pushing
#include "Vector2DStack.h"

void dbl(Vector2D& vector){
    vector *= 2;
}

int main(){
    Vector2D v1(2, 3), v2(10, 20), v3(5, 7);

    Vector2DArray arr(2);
    Vector2DStack st;
    arr.append(v1);
    arr.append(v2);
    arr.append(v3);
    arr.forEach(dbl);

    arr.remove(1);
    arr.remove(0);

    bool success;
    const Vector2D lastRemoved = arr.at(0, success);
    if (success)
        lastRemoved.print();
    else    
        std::printf("Neuspjesno dohvatanje.\n");

    st.push(v1);
    st.push(v2);
    st.push(v3);

    Vector2D lastPopped;
    while (st.pop(lastPopped)){
        lastPopped.print();
    }

    return 0;
    
    // radi sve kao sat
}