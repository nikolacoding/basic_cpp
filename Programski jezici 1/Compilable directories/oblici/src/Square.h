#ifndef SQUARE_H
#define SQUARE_H

#include "Shape2D.h"

class Square final : public Shape2D {
private:
    double m_side;

public:
    Square(double side = 1) : m_side(side) {}
    virtual const char* type() const override;
    virtual double getArea() const override;
    virtual double getPer() const override;
    virtual void scaleInPlace(const double q) override;
    virtual Shape2D* clone() const override;
};

#endif