#include "Array.h"
#include <iostream>
using string = const char *;
constexpr int defaultSize = 10;

static void LogLine(string s){
    std::cout << s << std::endl;
}

int Array::count = 0;

// podrazumijevani konstruktor
Array::Array() : _id(count + 1), _capacity(defaultSize), _size(0), _array(new int[_capacity]) {
    LogLine("Podrazumijevani konstruktor");
    count++;
}

// parametrizovani konstruktor
Array::Array(int n) : _id(count + 1), _capacity(n), _size(0), _array(new int[n]) {
    LogLine("Parametrizovani konstruktor");
    count++;
}

// delegirajuci konstruktor
Array::Array(int a, int b) : Array(a) {
    LogLine("Delegirajuci konstruktor A(a, b) -> A(a)");
}

// konstruktor kopije
Array::Array(const Array& original) : _id(count + 1), _capacity(original._capacity), _size(original._size), _array(new int[original._size]){
    LogLine("Konstruktor kopije");
    count++;

    for (int i = 0; i < original._size; i++){
        _array[i] = original._array[i];
    }
}

// konstruktor pomjeranja
Array::Array(Array&& original) : _id(count + 1), _capacity(original._capacity), _size(original._size), _array(original._array) {
    LogLine("Konstruktor pomjeranja");
    count++;

    original._size = 0;
    original._array = nullptr;
}

// destruktor
Array::~Array(){
    delete[] _array;
    count--;
}

// dodavanje na kraj niza sa signalizacijom uspjesnosti
bool Array::append(int value){
    if (this->_size < this->_capacity){
        this->_array[this->_size++] = value;
        return true;
    }
    return false;
}

// ispis svih clanova u jedan red
void Array::write(){
    using std::cout;
    using std::endl;

    cout << "A" << this->_id << ": ";
    for (int i = 0; i < this->_size; i++)
        cout << this->_array[i] << " ";
    cout << endl;
}

// geter velicine
int Array::getSize(){
    return this->_size;
}

// geter pokazivaca na pocetak dinamickog niza _array u okviru datog objekta (this)
int* Array::getArrayPtr(){
    return this->_array;
}