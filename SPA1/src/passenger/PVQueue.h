#ifndef PVQUEUE_H
#define PVQUEUE_H

#include "../passenger/PVLinkedList.h"

class PVQueue{
private:
    PVLinkedList* m_list;

public:
    PVQueue();
    ~PVQueue();

    void enqueue(const PassengerVehicle& vehicle);
    void enqueuePriority(const PassengerVehicle& vehicle);
    bool dequeue(PassengerVehicle& vehicle);
};

#endif