#include "../cargo/CVQueue.h"

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

bool CVQueue::dequeue(CargoVehicle& vehicle){
    CVListNode* toDequeue = this->m_list->getAtFront();
    if (!toDequeue){
        return false;
    }
    vehicle = toDequeue->getCargoVehicleData();
    this->m_list->removeFront();
    return true;
}

void CVQueue::displayAll() const {
    this->m_list->displayAll();
}