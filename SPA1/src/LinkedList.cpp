#include "LinkedList.h"

LinkedList::LinkedList(){
    this->m_head = nullptr;
}

bool LinkedList::isEmpty() const{
    return this->m_head == nullptr;
}   

void LinkedList::addToFront(const Vehicle& vehicle){
    ListNode* newHead = new ListNode(vehicle);
    if (!this->m_head){
        this->m_head = newHead;
        return;
    }
    newHead->m_next = this->m_head;
    this->m_head = newHead;
}   

void LinkedList::addToBack(const Vehicle& vehicle){
    ListNode* last = this->getAtBack();
    ListNode *newNode = new ListNode(vehicle);

    if (last)
        last->m_next = newNode;
    else
        this->m_head = newNode;
}

void LinkedList::removeFront(){
    // TODO: provjera da li postoji
    ListNode* toDelete = this->m_head;
    this->m_head = this->m_head->m_next;
    delete toDelete;
}

ListNode* LinkedList::getAtFront() const{
    return this->m_head;
}

ListNode* LinkedList::getAtBack() const {
    if (this->m_head == nullptr){
        return nullptr;
    }
    ListNode* current = this->m_head;
    while (current->m_next)
        current = current->m_next;
    return current;
}