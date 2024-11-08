#ifndef PASSENGERLISTNODE_H
#define PASSENGERLISTNODE_H

#include "../passenger/Passenger.h"

class PassengerListNode{
    Passenger m_passengerData;
public:
    PassengerListNode* m_next;

    PassengerListNode() = delete;
    explicit PassengerListNode(const Passenger& data);

    Passenger& getPassengerData();
};

#endif