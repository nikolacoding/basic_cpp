#include "../passenger/PassengerQueue.h"

PassengerQueue::PassengerQueue(){
    PassengerLinkedList* list = new PassengerLinkedList;
    m_list = list;
}

PassengerQueue::~PassengerQueue(){
    delete m_list;
}

void PassengerQueue::enqueue(const Passenger& vehicle){
    this->m_list->addToBack(vehicle);
}

bool PassengerQueue::dequeue(Passenger& vehicle){
    PassengerListNode* toDequeue = this->m_list->getAtFront();
    if (!toDequeue){
        return false;
    }
    vehicle = toDequeue->getPassengerData();
    this->m_list->removeFront();
    return true;
}