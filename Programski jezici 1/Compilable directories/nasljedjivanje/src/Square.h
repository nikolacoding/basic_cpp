#ifndef SQUARE_H
#define SQUARE_H

#include "Shape2D.h"

class Square : public Shape2D {
private:
    double m_side;
public:
    Square(double side = 1.0) : m_side(side) {};
    virtual const char* type() const;
    virtual double getArea() const override;
    virtual double getCircum() const override;

    virtual Square* rescale(const double quotient) override;
    virtual void rescaleInPlace(const double quotient) override;
    virtual Square* clone() const override;
};

#endif