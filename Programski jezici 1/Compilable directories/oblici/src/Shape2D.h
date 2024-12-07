#ifndef SHAPE2D_H
#define SHAPE2D_H

class Shape2D{
public:
    virtual const char* type() const = 0;
    virtual double getArea() const = 0;
    virtual double getPer() const = 0;

    virtual Shape2D* clone() const = 0;
    virtual Shape2D* operator*(const double q) const;
    virtual void operator*=(const double q);
    virtual Shape2D* scale(const double q) const;
    virtual void scaleInPlace(const double q) = 0;
};

#endif