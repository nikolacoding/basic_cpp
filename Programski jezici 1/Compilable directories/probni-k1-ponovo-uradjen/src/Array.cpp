#include "Array.h"

Array::Array(int initCapacity) : 
    m_capacity(initCapacity), m_size(0), m_content(new Complex[initCapacity]){
        
}

Array::Array(Array&& other){
    std::cout << "mc\n";
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_content = other.m_content;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_content = nullptr;
}

Array::~Array(){
    delete[] this->m_content;
}

Array& Array::operator=(const Array& lv) {
    std::cout << "dodjela: =&\n";
    if (this != &lv){
        this->m_size = lv.m_size;
        this->m_capacity = lv.m_capacity;
        
        Complex* newArray = new Complex[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
            newArray[i] = lv.at(i); 
    }
    return *this;
}

Array& Array::operator=(Array&& rv) {
    std::cout << "dodjela: =&&\n";
    if (this != &rv){
        this->m_size = rv.m_size;
        this->m_capacity = rv.m_capacity;
        this->m_content = rv.m_content;

        rv.m_size = 0;
        rv.m_capacity = 0;
        rv.m_content = nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Array& obj){
    for (int i = 0; i < obj.m_size; i++)
        stream << obj.at(i);
    
    return stream;
}

void Array::append(const Complex& obj) {
    if (this->m_size == this->m_capacity)
        this->realloc(this->m_capacity * 2);
    
    this->at(m_size++) = obj;
}

// pretpostavlja se da pozivalac nece pozvati funkciju sa nepravilnim indeksom
// (van opsega niza) kao argumentom
Complex& Array::at(const int index){
    return this->m_content[index];
}

const Complex& Array::at(const int index) const {
    return this->m_content[index];
}

Array Array::transform(Complex (*f)(Complex)) const {
    Array newArray;

    for (int i = 0; i < this->m_size; i++)
        newArray.append((*f)(this->at(i)));
    
    return newArray;
}

void Array::realloc(int newCapacity){
    if (newCapacity <= 0)
        newCapacity = 1;
    
    this->m_capacity = newCapacity;
    Complex* newArray = new Complex[newCapacity];

    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->at(i);
    
    delete[] this->m_content;
    this->m_content = newArray;
}