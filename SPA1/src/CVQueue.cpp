#include "CVQueue.h"

CVQueue::CVQueue(){
    CVLinkedList* list = new CVLinkedList;
    m_list = list;
}

CVQueue::~CVQueue(){
    delete m_list;
}

void CVQueue::enqueue(const CargoVehicle& vehicle){
    this->m_list->addToBack(vehicle);
}

void CVQueue::enqueuePriority(const CargoVehicle& vehicle){
    this->m_list->addToFront(vehicle);
}

bool CVQueue::dequeue(CargoVehicle& vehicle){
    CVListNode* toDequeue = this->m_list->getAtFront();
    if (!toDequeue){
        return false;
    }
    vehicle = toDequeue->m_passengerVehicleData;
    this->m_list->removeFront();
    return true;
}