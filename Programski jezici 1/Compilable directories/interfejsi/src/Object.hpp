#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include "Item.hpp"
#include "IPrintable.hpp"
#include "IStringConvertible.hpp"

class Object : IPrintable, IStringConvertible {
public:
    virtual std::string toString() const override;
    virtual void print() const override;
    virtual bool equals(const Object& other);
};

#endif