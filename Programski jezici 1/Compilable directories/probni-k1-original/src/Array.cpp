#include "Array.hpp"

Array::Array(int initCapacity) : 
    m_capacity(initCapacity), m_size(0), m_content(new Complex[initCapacity]){

}

Array::Array(Array&& other){
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    this->m_content = other.m_content;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_content = nullptr;
}

Array::~Array() {
    delete[] this->m_content;
}

void Array::append(const Complex& obj){
    if (this->m_capacity == this->m_size)
        realloc(this->m_capacity * 2);

    this->m_content[this->m_size++] = obj;
}

// adekvatan indeks je odgovornost pozivaoca
// tj. pozivanje sa indeksom sa segmenta [0, this->m_size - 1]
Complex& Array::at(const int index) {
    return this->m_content[index];
}

const Complex& Array::at(const int index) const {
    return this->m_content[index];
}

Array Array::transform(Complex (*f)(Complex)) const {
    Array newArray;

    for (int i = 0; i < this->m_size; i++)
        newArray.append((*f)((*this).at(i)));

    return newArray;
}

void Array::realloc(int newCapacity){
    if (newCapacity < 0)
        newCapacity = 0;

    Complex* newArray = new Complex[newCapacity];
    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_content[i];
    
    delete[] this->m_content;
    this->m_content = newArray;
}

std::ostream& operator<<(std::ostream& stream, const Array& obj){
    for (int i = 0; i < obj.m_size; i++){
        stream << obj.m_content[i] << " ";
        stream << std::endl;
    }
    stream << std::endl;
    return stream;
}