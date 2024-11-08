#include "../passenger/PassengerLinkedList.h"

PassengerLinkedList::PassengerLinkedList(){
    this->m_head = nullptr;
}

bool PassengerLinkedList::isEmpty() const{
    return this->m_head == nullptr;
}   

void PassengerLinkedList::addToFront(const Passenger& vehicle){
    PassengerListNode* newHead = new PassengerListNode(vehicle);
    if (!this->m_head){
        this->m_head = newHead;
        return;
    }
    newHead->m_next = this->m_head;
    this->m_head = newHead;
}   

void PassengerLinkedList::addToBack(const Passenger& vehicle){
    PassengerListNode* last = this->getAtBack();
    PassengerListNode* newNode = new PassengerListNode(vehicle);

    if (last)
        last->m_next = newNode;
    else
        this->m_head = newNode;
}

void PassengerLinkedList::removeFront(){
    PassengerListNode* toDelete = this->m_head;
    if (toDelete){
        this->m_head = this->m_head->m_next;
        delete toDelete;
    }
}

PassengerListNode* PassengerLinkedList::getAtFront() const{
    return this->m_head;
}

PassengerListNode* PassengerLinkedList::getAtBack() const {
    if (this->isEmpty())
        return nullptr;

    PassengerListNode* current = this->m_head;
    while (current->m_next)
        current = current->m_next;
    return current;
}