#ifndef SET_H
#define SET_H

#include "Vector.hpp"

class Set{
private:
    int m_capacity;
    int m_size;
    Vector* m_vectors;

public:
    Set(int initCapacity = 1);
    Set(const Set& other);
    Set(Set&& other);
    ~Set();

    Set& operator=(const Set& other);
    Set& operator=(Set&& other);

    void add(const Vector& vector);
    bool equals(const Set& other);

    void operator+=(const Vector& vector);
    bool operator==(const Set& other);
    Set operator+(const Set& other) const;
    friend std::ostream& operator<<(std::ostream& stream, const Set& obj);

    int getSize() const { return this->m_size; }
    void displayAll() const;

private:
    bool isFull() const { return this->m_capacity == this->m_size; }
    void realloc(int newCapacity);
};

#endif