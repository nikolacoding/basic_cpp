#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

class Queue{
private:
    LinkedList* m_list;

public:
    Queue(LinkedList* list);

    void enqueue(const Vehicle& vehicle);
    void enqueuePriority(const Vehicle& vehicle);
    Vehicle dequeue(bool& success);
};

#endif