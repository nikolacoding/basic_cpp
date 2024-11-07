#ifndef CVLINKEDLIST_H
#define CVLINKEDLIST_H

#include "CVListNode.h"
#include "CargoVehicle.h"

class CVLinkedList{
private:
    CVListNode *m_head;

public:
    CVLinkedList();

    bool isEmpty() const;
    void addToFront(const CargoVehicle& vehicle);
    void addToBack(const CargoVehicle& vehicle);

    void removeFront();

    CVListNode* getAtFront() const;
    CVListNode* getAtBack() const;
};

#endif