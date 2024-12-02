#ifndef VECTOR_H
#define VECTOR_H

#include "Complex.hpp"

class Vector{
public:
    static int m_n;
    
private:
    Complex* m_content;

public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();

    void operator=(const Vector& other);
    void operator=(Vector&& other);

    void display() const;

    Complex& operator[](const int index) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    friend std::ostream& operator<<(std::ostream& stream, const Vector& obj);
};

#endif