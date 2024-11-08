#include "../passenger/PVQueue.h"

PVQueue::PVQueue(){
    PVLinkedList* list = new PVLinkedList;
    m_list = list;
}

PVQueue::~PVQueue(){
    delete m_list;
}

void PVQueue::enqueue(const PassengerVehicle& vehicle){
    this->m_list->addToBack(vehicle);
}

void PVQueue::enqueuePriority(const PassengerVehicle& vehicle){
    this->m_list->addToFront(vehicle);
}

bool PVQueue::dequeue(PassengerVehicle& vehicle){
    PVListNode* toDequeue = this->m_list->getAtFront();
    if (!toDequeue){
        return false;
    }
    vehicle = toDequeue->m_passengerVehicleData;
    this->m_list->removeFront();
    return true;
}