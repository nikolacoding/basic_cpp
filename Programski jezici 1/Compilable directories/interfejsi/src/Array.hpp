#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Object.hpp"

class Array final {
private:
    int m_size;
    int m_capacity;
    Object** m_objects;

public:
    Array(int initCapacity = 1);

    // kopiranje
    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;

    // pomjeranje
    Array(Array&& other);
    Array& operator=(Array&& other);

    ~Array();

    void append(Object* const obj);
    int getSize() const { return this->m_size; }
    Object* at(int index) const;

private:
    void dispose();
    void realloc(int newCapacity);
};

#endif