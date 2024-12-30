#pragma once
#include "Item.h"

class Pen : public Item
{
public:
    using Item::Item;

    virtual Object* clone() override{
        return new Pen(*this);
    }
};