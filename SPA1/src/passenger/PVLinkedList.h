#ifndef PVLINKEDLIST_H
#define PVLINKEDLIST_H

#include "../passenger/PVListNode.h"
#include "../passenger/PassengerVehicle.h"

class PVLinkedList{
private:
    PVListNode* m_head;

public:
    PVLinkedList();

    bool isEmpty() const;

    void addToFront(const PassengerVehicle& vehicle);
    PVListNode* getAtFront() const;
    void removeFront();

    void addToBack(const PassengerVehicle& vehicle);
    PVListNode* getAtBack() const;
};

#endif