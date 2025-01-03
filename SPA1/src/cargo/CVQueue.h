#ifndef CVQUEUE_H
#define CVQUEUE_H

#include "../cargo/CVLinkedList.h"

class CVQueue{
private:
    CVLinkedList* m_list;

public:
    CVQueue();
    ~CVQueue();

    void enqueue(const CargoVehicle& vehicle);
    bool dequeue(CargoVehicle& vehicle);
    void displayAll() const;
};

#endif