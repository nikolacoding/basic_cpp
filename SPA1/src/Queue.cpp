#include "Queue.h"

Queue::Queue(LinkedList* list) : m_list(list) {

}

void Queue::enqueue(const Vehicle& vehicle){
    this->m_list->addToBack(vehicle);
}

void Queue::enqueuePriority(const Vehicle& vehicle){
    this->m_list->addToFront(vehicle);
}

Vehicle Queue::dequeue(bool& success){
    ListNode* toDequeue = this->m_list->getAtFront();
    if (!toDequeue){
        success = false;
        return Vehicle::invalidVehicle;
    }
    Vehicle ret = toDequeue->m_vehicleData;
    this->m_list->removeFront();
    success = true;
    return ret;
}