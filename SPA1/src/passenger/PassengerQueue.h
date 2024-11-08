#ifndef PASSENGERQUEUE_H
#define PASSENGERQUEUE_H

#include "../passenger/PassengerLinkedList.h"

class PassengerQueue{
private:
    PassengerLinkedList* m_list;

public:
    PassengerQueue();
    ~PassengerQueue();

    void enqueue(const Passenger& passenger);
    bool dequeue(Passenger& passenger);
};

#endif