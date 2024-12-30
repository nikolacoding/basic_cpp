#pragma once
#include "Object.h"
#include "Sale.h"
#include "Discount.h"

class DiscountSpecial: public Discount{
protected:
    int limit;
public:
    DiscountSpecial(const Sale& sale, double discount, int limit=3): Discount(sale, discount), limit(limit){}

    int totalPrice() const override
    {
        if(sale.size() >= limit){
            return static_cast<int>(sale.totalPrice() * (1 - discount));
        }
        return sale.totalPrice();
    }

    virtual Object* clone() override
    {
        return new DiscountSpecial(*this);
    }

};