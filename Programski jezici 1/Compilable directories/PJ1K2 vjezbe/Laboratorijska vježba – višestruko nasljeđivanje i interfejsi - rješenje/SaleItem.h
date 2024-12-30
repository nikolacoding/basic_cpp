#include "Item.h"

class SaleItem: public Item{
private:
    const Item& referenced;
    const int count;
public:
    SaleItem(const Item& item, int count=1): referenced(item), count(count), Item(item.getName(), item.getPrice() * count) {};

    int getCount() const{
        return count;
    }

    virtual Object* clone() override{
        return new SaleItem(*this);
    }

};