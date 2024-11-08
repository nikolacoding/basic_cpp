#ifndef CARGOSTACK_H
#define CARGOSTACK_H

#include "../cargo/Cargo.h"

class CargoStack{
private:
    int m_topOfStack;
    int m_capacity;
    Cargo* m_cargoArray;

    void realloc(int newCapacity);
public:
    CargoStack();

    bool isFull() const;
    bool isEmpty() const;
    int getSize() const;
    void displayAll() const;

    void push(const Cargo& cargo);
    bool pop(Cargo& cargo);
};

#endif