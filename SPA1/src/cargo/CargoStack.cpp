#include "../cargo/CargoStack.h"

CargoStack::CargoStack() : 
m_topOfStack(-1), m_capacity(2), m_cargoArray(new Cargo[2]){ }

void CargoStack::realloc(int newCapacity){
    Cargo* newArray = new Cargo[newCapacity];
    for (int i = 0; i < this->getSize(); i++){
        newArray[i] = this->m_cargoArray[i];
    }
    delete[] this->m_cargoArray;
    this->m_cargoArray = newArray;
}

bool CargoStack::isFull() const {
    return this->m_topOfStack == this->m_capacity - 1;
}

bool CargoStack::isEmpty() const {
    return this->m_topOfStack == -1;
}

int CargoStack::getSize() const {
    return this->m_topOfStack + 1;
}

void CargoStack::displayAll() const {
    for (int i = 0; i < this->getSize(); i++){
        std::cout << "   " << i + 1 << ": " << 
        this->m_cargoArray[i].getName() << std::endl;
    }
}

void CargoStack::push(const Cargo& cargo){
    if (this->m_capacity == 0){
        this->m_capacity = 1;
        realloc(this->m_capacity);
    }
    if (this->isFull()){
        this->m_capacity *= 2;
        realloc(this->m_capacity);
    }

    this->m_cargoArray[++m_topOfStack] = cargo;
}

bool CargoStack::pop(Cargo& cargo){
    if (this->isEmpty())
        return false;
    
    cargo = this->m_cargoArray[this->m_topOfStack--];

    if (this->getSize() <= this->m_capacity / 2){
        this->m_capacity /= 2;
        this->realloc(this->m_capacity);
    }
    return true;
}