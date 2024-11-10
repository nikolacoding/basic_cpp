#ifndef STACK_H
#define STACK_H
#include "Point.h"

class Stack {
private:
    int capacity;
    int topIndex;
    Point* data;

public:
    // explicit - zabrana implicitne konverzije konstruktora
    // mora se strogo koristiti oblik npr. Stack s(4) a ne Stack s = 4;
    explicit Stack(int initialCapacity = 10);
    ~Stack();

    void push(Point& value);
    bool pop(Point& poppedPoint);
    Point& top();
    bool isEmpty();
    int size();

private:
    void resize(int newCapacity);
};

#endif