#ifndef PASSENGERLINKEDLIST_H
#define PASSENGERLINKEDLIST_H

#include "../passenger/PassengerListNode.h"
#include "../passenger/Passenger.h"

class PassengerLinkedList{
private:
    PassengerListNode* m_head;

public:
    PassengerLinkedList();

    bool isEmpty() const;

    void addToFront(const Passenger& passenger);
    PassengerListNode* getAtFront() const;
    void removeFront();

    void addToBack(const Passenger& passenger);
    PassengerListNode* getAtBack() const;
};

#endif