#include "Point.h"
#include "Stack.h"
#include <cstdio>

int main(){
    // stek je logicki prazan kad je topIndex = -1 tj. kada je size() + 1 == 0
    // stek je logicki pun kad je topIndex + 1 = capacity tj. size() == capacity
  
    Stack s(4); // instanciramo stek sa inicijalnim kapacitetom 4
    Point lastPopped;

    Point p1(3, 4);
    Point p2(12, 17);
    Point p3(3, 3);
    Point p4(7, 4);
    Point p5(11, 0);
    Point p6(4, 1);
    Point p7(6, 6);
    Point p8(5, 4);
    Point p9(1, 2);

    // testiramo push() -> stavljamo 9 Pointova na stek
    s.push(p1); // 1/4
    s.push(p2); // 2/4
    s.push(p3); // 3/4
    s.push(p4); // 4/4
    s.push(p5); // preliva se kapacitet steka, poziva se Stack::resize(8), bice ispisano na stdout
                // 5/8
    s.push(p6); // 6/8
    s.push(p7); // 7/8
    s.push(p8); // 8/8
    s.push(p9); // opet se povecava, Stack::resize(16), bice ispisano na stdout
                // 9/16

    s.pop(lastPopped);  // 8/16 velicina steka pada ispod pola kapaciteta, poziva se Stack::resize(8)
                        // bice ispisano na stdout
    s.pop(lastPopped);  // 7/8 
    s.pop(lastPopped);  // 6/8
    s.pop(lastPopped);  // 5/8
    s.pop(lastPopped);  // 4/4 ponovo se smanjuje, Stack::resize(4), bice ispisano na stdout
    s.pop(lastPopped);  // 3/4 
    s.pop(lastPopped);  // 2/4 ponovo se smanjuje, Stack::resize(2), bice ispisano na stdout
                        // ...

    // testiramo da li top() pravilno vraca referencu
    auto topPoint = s.top();
    printf("%d %d\n", lastPopped.getX(), lastPopped.getY());
    printf("%d %d\n", topPoint.getX(), topPoint.getY());

    // testiramo signalizaciju uspjesnosti funkcije pop()
    if (!s.pop(lastPopped)) printf("prazno\n"); // 1/4
    if (!s.pop(lastPopped)) printf("prazno\n"); // 0/4
    if (!s.pop(lastPopped)) printf("prazno\n"); // prazno
    if (!s.pop(lastPopped)) printf("prazno\n"); // prazno

    // moguce da postoji problem sa radom sa stekom kapaciteta 0 ali nemam vremena da to popravljam

    return 0;
}