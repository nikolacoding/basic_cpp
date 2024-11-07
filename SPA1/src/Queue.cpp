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
    Vehicle ret = this->m_list->getAtFront()->m_vehicleData;
    this->m_list->removeFront();
    return ret;
}