#ifndef MATCH_H
#define MATCH_H

#include "Ticket.h"

class Match final : public Ticket {
private:
    bool isVip;
    virtual void setPrice() override {
        this->m_finalPrice = Ticket::m_basePrice + isVip * 50;
    }

public:
    Match(bool isVip = false) : isVip(isVip) { this->setPrice(); }
};

#endif