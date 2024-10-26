#include "IntArray.h"
#include <iostream>

const int defaultMaxSize = 10;

IntArray::IntArray(){
    this->size = 0;
    this->maxSize = defaultMaxSize;
    this->array = new int[this->maxSize];
}

IntArray::~IntArray(){
    delete[] this->array;
    std::cout << "Deleted!" << std::endl;
}

bool IntArray::isFull() const {
    return this->size == this->maxSize;
}

bool IntArray::isEmpty() const {
    return this->size == 0;
}

void IntArray::writeAll() const {
    using std::cout;
    using std::endl;

    if (!this->isEmpty()){
        cout << "Niz (" << this->size << " clanova):" << endl;
        for (int i = 0; i < this->size; i++)
            cout << this->array[i] << endl;
    }
    else cout << "Empty!";
}

bool IntArray::append(int value){
    if (!this->isFull()){
        this->array[this->size++] = value;
        return true;
    }

    return false;
}

int IntArray::pop(){
    if (!this->isEmpty()){
        int v = array[--this->size];
        return v;
    }
    
    // daleko od optimalnog
    return INT16_MAX;
}