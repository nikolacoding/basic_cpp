#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape2D.h"

class Rectangle final : public Shape2D{
private:
    double m_a;
    double m_b;

public:
    Rectangle(double a = 1, double b = 1) : m_a(a), m_b(b) {}
    virtual const char* type() const override;
    virtual double getArea() const override;
    virtual double getPer() const override;
    virtual void scaleInPlace(const double q) override;
    virtual Shape2D* clone() const override;
};

#endif