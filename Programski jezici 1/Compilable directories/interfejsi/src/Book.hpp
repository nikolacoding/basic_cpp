#ifndef BOOK_HPP
#define BOOK_HPP

#include "Item.hpp"

class Book final : public Item {
public:
    Book(double price = 0.0, std::string name = "Unnamed book") : Item(price, name) {}
};

#endif