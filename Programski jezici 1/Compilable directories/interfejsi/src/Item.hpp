#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Object.hpp"

class Item : public Object {
protected:
    double m_price;
    std::string m_name;

public:
    Item(double price = 0.0, std::string name = "Unnamed item") :
        m_price(price), m_name(name) {}

    double m_price;
    std::string m_name;

    virtual std::string toString() const override {

    }

    virtual void print() const override {

    }

    virtual bool equals(const Object& other) {
        
    }
};

#endif