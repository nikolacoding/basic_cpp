#ifndef SHAPE2D_H
#define SHAPE2D_H

class Shape2D{
public:
    virtual const char* type() const = 0;
    virtual double getArea() const = 0;
    virtual double getCircum() const = 0;

    // kloniranje
    virtual Shape2D* clone() const = 0;

    // skaliranje
    virtual Shape2D* operator*(const double quotient);
    virtual Shape2D* rescale(const double quotient) = 0;
    virtual void rescaleInPlace(const double quotient) = 0;
};

#endif