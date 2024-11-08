#ifndef CVLINKEDLIST_H
#define CVLINKEDLIST_H

#include "../cargo/CVListNode.h"
#include "../cargo/CargoVehicle.h"

class CVLinkedList{
private:
    CVListNode *m_head;

public:
    CVLinkedList();

    bool isEmpty() const;

    CVListNode* getAtFront() const;
    void addToFront(const CargoVehicle& vehicle);
    void removeFront();

    CVListNode* getAtBack() const;
    void addToBack(const CargoVehicle& vehicle);

    void displayAll() const;  
};

#endif