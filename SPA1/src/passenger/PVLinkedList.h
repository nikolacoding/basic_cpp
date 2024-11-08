#ifndef PVLINKEDLIST_H
#define PVLINKEDLIST_H

#include "../passenger/PVListNode.h"
#include "../passenger/PassengerVehicle.h"

class PVLinkedList{
private:
    PVListNode *m_head;

public:
    PVLinkedList();

    bool isEmpty() const;
    void addToFront(const PassengerVehicle& vehicle);
    void addToBack(const PassengerVehicle& vehicle);

    void removeFront();

    PVListNode* getAtFront() const;
    PVListNode* getAtBack() const;
};

#endif