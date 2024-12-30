#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
using std::string;

class Ticket {
protected:
    static __int64 m_basePrice;
    string m_name;
    string m_date;
    __int64 m_finalPrice; 

public:
    virtual void setPrice() = 0;
    __int64 getPrice() const { return this->m_finalPrice; }
};

#endif