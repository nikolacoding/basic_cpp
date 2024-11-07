#ifndef PVQUEUE_H
#define PVQUEUE_H

#include "CVLinkedList.h"

class CVQueue{
private:
    CVLinkedList* m_list;

public:
    CVQueue();
    ~CVQueue();

    void enqueue(const CargoVehicle& vehicle);
    void enqueuePriority(const CargoVehicle& vehicle);
    bool dequeue(CargoVehicle& vehicle);
};

#endif