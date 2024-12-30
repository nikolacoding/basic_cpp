#pragma once
#include "Object.h"
#include "Sale.h"

class Discount: public Sale{
protected:
    const Sale& sale;
    double discount;

public:
    Discount(const Sale& sale, double discount): sale(sale), discount(discount){}

    int totalPrice() const override
    {
        return static_cast<int>(sale.totalPrice() * (1 - discount));
    }

    std::string toString() const override
    {
        std::string str = sale.toString();
        str += "\nDiscount: " + std::to_string(discount * 100) + "%";
        str += "\nDiscounted Total Price: " + std::to_string(totalPrice());
        return str;
    }

    virtual Object* clone() override
    {
        return new Discount(*this);
    }

};