#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape2D.h"

class Circle final : public Shape2D{
private:
    double m_radius;

public:
    Circle(double radius = 1) : m_radius(radius) {}
    virtual const char* type() const override;
    virtual double getArea() const override;
    virtual double getPer() const override;
    virtual void scaleInPlace(const double q) override;
    virtual Shape2D* clone() const override;
};

#endif