#ifndef LISTNODE_H
#define LISTNODE_H

#include "Vehicle.h"

class ListNode{
public:
    Vehicle m_vehicleData;
    ListNode* m_next;

    ListNode(Vehicle data);
    //~ListNode();
};

#endif