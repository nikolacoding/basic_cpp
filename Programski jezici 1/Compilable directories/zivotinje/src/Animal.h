#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal{
protected:
    double m_height;
    double m_weight;

public:
    Animal(double height = 1, double weight = 1) : 
        m_weight(weight), m_height(height) {}

    double getHeight() const { return this->m_height; }
    double getWeight() const { return this->m_weight; }
    
    virtual Animal* operator*(const double q) const;
    virtual void operator*=(const double q);

    virtual Animal* operator+(const Animal& other) const;
    virtual void operator+=(const Animal& other);

    virtual Animal* clone() const = 0;
    virtual void scale(const double q) = 0;
    virtual void add(const Animal& other) = 0;

    virtual void sound() const = 0;
    virtual void logMetrics() const;
};

#endif