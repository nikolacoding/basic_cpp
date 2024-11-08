#ifndef CARGOSTACK_H
#define CARGOSTACK_H

#include "../cargo/Cargo.h"

class CargoStack{
private:
    int m_topOfStack;
    Cargo* m_cargoArray;
public:
    CargoStack();
    void push(const Cargo& cargo);
    bool pop(Cargo& cargo);
};

#endif