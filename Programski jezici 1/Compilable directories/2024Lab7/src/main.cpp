#include <iostream>
#include <deque>
#include <memory>
using std::deque;
using std::unique_ptr;
using std::make_unique;

#include "Concert.h"
#include "Movie.h"
#include "Match.h"
#include "Ticket.h"

__int64 Ticket::m_basePrice = 10;

int main(void){
    deque<unique_ptr<Ticket>> tickets;

    tickets.push_back(std::move(make_unique<Concert>(Concert())));
    tickets.push_back(std::move(make_unique<Movie>(Movie(false))));
    tickets.push_back(std::move(make_unique<Movie>(Movie(true))));
    tickets.push_back(std::move(make_unique<Match>(Match(false))));
    tickets.push_back(std::move(make_unique<Match>(Match(true))));

    for (const auto& t : tickets)
        std::cout << t->getPrice() << std::endl;
}