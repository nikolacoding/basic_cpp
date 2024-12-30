#ifndef CONCERT_H
#define CONCERT_H

#include "Ticket.h"

class Concert final : public Ticket {
public:
    Concert() { this->setPrice(); }
private:
    string m_performer;
    virtual void setPrice() override {
        this->m_finalPrice = Ticket::m_basePrice * 1.2;
    }
};

#endif