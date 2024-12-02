#ifndef ARRAY_H
#define ARRAY_H

#include "Complex.h"

class Array{
private:
    int m_capacity;
    int m_size;
    Complex* m_content;

public:
    Array(int initCapacity = 0);
    Array(const Array&& other) = delete;
    Array(Array&& other);
    ~Array();

    Array& operator=(const Array& lv);
    Array& operator=(Array&& rv);

    friend std::ostream& operator<<(std::ostream& stream, const Array& obj);

    void append(const Complex& obj);
    Complex& at(const int index);
    const Complex& at(const int index) const;

    Array transform(Complex (*f)(Complex)) const;

private:
    void realloc(int newCapacity);
};

#endif