#include "../passenger/PVLinkedList.h"

PVLinkedList::PVLinkedList(){
    this->m_head = nullptr;
}

bool PVLinkedList::isEmpty() const{
    return this->m_head == nullptr;
}   

void PVLinkedList::addToFront(const PassengerVehicle& vehicle){
    PVListNode* newHead = new PVListNode(vehicle);
    if (!this->m_head){
        this->m_head = newHead;
        return;
    }
    newHead->m_next = this->m_head;
    this->m_head = newHead;
}   

void PVLinkedList::addToBack(const PassengerVehicle& vehicle){
    PVListNode* last = this->getAtBack();
    PVListNode* newNode = new PVListNode(vehicle);

    if (last)
        last->m_next = newNode;
    else
        this->m_head = newNode;
}

void PVLinkedList::removeFront(){
    PVListNode* toDelete = this->m_head;
    if (toDelete){
        this->m_head = this->m_head->m_next;
        delete toDelete;
    }
}

PVListNode* PVLinkedList::getAtFront() const{
    return this->m_head;
}

PVListNode* PVLinkedList::getAtBack() const {
    if (this->isEmpty())
        return nullptr;

    PVListNode* current = this->m_head;
    while (current->m_next)
        current = current->m_next;
    return current;
}