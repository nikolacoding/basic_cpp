#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
#include "Vehicle.h"

class LinkedList{
private:
    ListNode *m_head;

public:
    LinkedList();

    bool isEmpty() const;
    void addToFront(const Vehicle& vehicle);
    void addToBack(const Vehicle& vehicle);

    void removeFront();

    ListNode* getAtFront() const;
    ListNode* getAtBack() const;
};

#endif