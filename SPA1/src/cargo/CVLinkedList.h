#ifndef CVLINKEDLIST_H
#define CVLINKEDLIST_H

#include "../cargo/CVListNode.h"
#include "../cargo/CargoVehicle.h"

class CVLinkedList{
private:
    CVListNode *m_head;

public:
    CVLinkedList();

    bool isEmpty() const;
    void addToFront(const CargoVehicle& vehicle);
    void addToBack(const CargoVehicle& vehicle);

    void removeFront();

    CVListNode* getAtFront() const;
    CVListNode* getAtBack() const;

    // TODO: implementirati ispis svih vozila i njihove robe u formatiranom
    // obliku gdje se jasno vidi gdje je koji u odnosu na granicni prelaz;
    // ovo se poziva kad uvedemo sva teretna vozila u red
    void displayAll() const;  
};

#endif