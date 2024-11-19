#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array{
private:
    int m_capacity;
    int m_size;
    int* m_data;

public:
    // Konstruktor/destruktor
    Array(int initCapacity = 1);
    Array(const Array& other);
    // ~Array();

    // Konstantne metode
    void displayAll() const;

    // Dodavanje
    void append(const int value);
    bool pop(int& value);

    // Reference
    int& at(const int index) const;

    // Operacije sa iteracijom kroz cijeli niz
    Array filter(bool (*condition)(const int)) const;
    Array transform(int (*tr)(const int)) const;

    // Operatori

        // Mnozenje konstantom
    friend Array operator*(const Array&, const int);
    friend Array operator*(const int, const Array&);

        // Dodavanje elementa na kraj
    Array operator+(const int value) const;
    void operator+=(const int value);

        // Sabiranje dva niza
    Array operator+(const Array& other) const;
    void operator+=(const Array& other);

        // Indeksiranje
    int& operator[](const int index) const;

        // Direktna uporedba
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;

        // Poredjenje po velicini
    bool operator>(const Array& other) const;
    bool operator>=(const Array& other) const;
    bool operator<(const Array& other) const;
    bool operator<=(const Array& other) const;
    
        // In-place transformacija prema funkciji
    void operator()(void (*f)(int&));
    void operator()(int from, int to, void (*f)(int&));

        // Ispis na stdout
    friend std::ostream& operator<<(std::ostream& ostream, const Array& array);

        // Unos sa stdin
    friend std::istream& operator>>(std::istream& istream, Array& array);

private:
    inline bool isFull();
    inline bool isEmpty();
    void realloc(int newCapacity);
};

#endif