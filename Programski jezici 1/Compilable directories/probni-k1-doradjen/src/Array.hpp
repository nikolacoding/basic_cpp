#ifndef ARRAY_H
#define ARRAY_H

#include "Complex.hpp"

class Array{
private:
    int m_capacity;
    int m_size;
    Complex* m_content;

public:
    Array(int initCapacity = 1);
    Array(const Array& other) = delete;
    Array(Array&& other);
    ~Array();

    void append(const Complex& obj);
    Complex& at(const int index);
    const Complex& at(const int index) const;
    Array transform(Complex (*f)(Complex)) const;

    friend std::ostream& operator<<(std::ostream& stream, const Array& obj);

private:
    void realloc(int newCapacity);
};

#endif