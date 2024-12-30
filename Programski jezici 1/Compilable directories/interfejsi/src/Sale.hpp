#ifndef SALE_HPP
#define SALE_HPP

#include "Array.hpp"

class Sale final : public Object {
private:
    Array m_items;

public:
    friend std::ostream& operator<<(std::ostream& stream, Sale& object);
    double totalPrice() const;

    int getSize() const { return this->m_items.getSize(); }
    void append(Object* obj) { m_items.append(obj); }
    Object* at(int index) const { return m_items.at(index); }
};

#endif