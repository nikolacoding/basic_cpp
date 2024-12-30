#ifndef MOVIE_H
#define MOVIE_H

#include "Ticket.h"

class Movie final : public Ticket {
private:
    bool is3D;
    virtual void setPrice() override {
        this->m_finalPrice = Ticket::m_basePrice + is3D * 5;
    }

public:
    Movie(bool is3D = false) : is3D(is3D) { this->setPrice(); }
};

#endif