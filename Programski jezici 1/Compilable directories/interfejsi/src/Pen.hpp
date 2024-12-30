#ifndef PEN_HPP
#define PEN_HPP

#include "Item.hpp"

class Pen final : public Item {
public:
    Pen(double price = 0.0, std::string name = "Unnamed pen") : Item(price, name) {}
};

#endif