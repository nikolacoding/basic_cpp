#include "../cargo/CVLinkedList.h"

CVLinkedList::CVLinkedList(){
    this->m_head = nullptr;
}

bool CVLinkedList::isEmpty() const{
    return this->m_head == nullptr;
}   

void CVLinkedList::addToFront(const CargoVehicle& vehicle){
    CVListNode* newHead = new CVListNode(vehicle);
    if (!this->m_head){
        this->m_head = newHead;
        return;
    }
    newHead->m_next = this->m_head;
    this->m_head = newHead;
}   

void CVLinkedList::addToBack(const CargoVehicle& vehicle){
    CVListNode* last = this->getAtBack();
    CVListNode* newNode = new CVListNode(vehicle);

    if (last)
        last->m_next = newNode;
    else
        this->m_head = newNode;
}

void CVLinkedList::removeFront(){
    CVListNode* toDelete = this->m_head;
    if (toDelete){
        this->m_head = this->m_head->m_next;
        delete toDelete;
    }
}

CVListNode* CVLinkedList::getAtFront() const{
    return this->m_head;
}

CVListNode* CVLinkedList::getAtBack() const {
    if (this->isEmpty())
        return nullptr;

    CVListNode* current = this->m_head;
    while (current->m_next)
        current = current->m_next;
    return current;
}

void CVLinkedList::displayAll() const {
    CVListNode* current = m_head;
    std::cout << "Trenutni poredak u redu:\n";
    while (current){
        CargoVehicle& currentVehicle = current->m_cargoVehicleData;

        std::printf("Vozilo [ID: %d]\n", currentVehicle.getId());
        currentVehicle.logCargo();
        std::printf("\n");

        current = current->m_next;
    }
}