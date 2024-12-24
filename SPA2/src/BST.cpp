#include "BST.hpp"

#include <iostream>
#include <vector>

BST::~BST(){
    this->dispose();
}

// iterativna implementacija dodavanja
void BST::insert(BSTNode* const node){
    if (!this->m_head){
        this->m_head = node;
        return;
    }

    // ukoliko pronadjemo cvor sa identicnim kljucem (distancom), ulancavamo novi kao clan
    // paralelne jednostruke ulancane liste koristeci m_next pokazivac
    BSTNode* anchor;
    if (anchor = this->find(node->m_distance)){
        while (anchor->m_next)
            anchor = anchor->m_next;
        anchor->m_next = node;
        return;
    }

    // inicijalizujemo dva pokazivaca, jedan koji prednjaci (current) i jedan koji kaska (prev);
    // [1] - ako current dostigne nullptr, znamo da je current "spao" sa BST-a i da je prev u tom istom momentu 
    // na cvoru koji ce biti roditelj novododanom, te prosto provjeravamo u kom smjeru trebamo da dodamo novi cvor
    // [2] - ako current nije jos dostigao nullptr, nastavljamo standardan obilazak BST-a u skladu sa
    // velicinom cvora koji dodajemo
    BSTNode* prev = nullptr;
    BSTNode* current = this->m_head;
    while (true){
        
        // [1]
        if (current == nullptr){
            if (node->m_distance > prev->m_distance)
                prev->m_right = node;
            else  // ne moze se desiti da je jednako zbog prvog if bloka
                prev->m_left = node;
            return;
        }
        
        // [2]
        prev = current;
        if (node->m_distance > current->m_distance)
            current = current->m_right;
        else // ne moze se desiti da je jednako zbog prvog if bloka
            current = current->m_left;
    }
}

void BST::operator+=(BSTNode* const node) {
    this->insert(node);
}

// pretrazivanje po udaljenosti (iterativno)
// [1] - pokazivac je "spao" sa stabla prije nailaska na cvor - trazeni cvor ne postoji u stablu
// [2] - pokazivac je naisao na cvor sa trazenim kljucem - trazeni cvor je pronadjen i vraca se
// [3] - nije se desilo ni [1] ni [2] - nastavljamo kretanje niz BST
BSTNode* BST::find(const int distance) const {
    if (!this->m_head)
        return nullptr;

    BSTNode* current = this->m_head;
    while (true){
        // [1]
        if (current == nullptr)
            return nullptr;

        // [2]
        if (current->m_distance == distance)
            return current;
        
        // [3]
        if (distance > current->m_distance)
            current = current->m_right;
        else
            current = current->m_left;
    }
}

// potencijalno redundantna funkcija ali nisam mogao obici ogranicenje lambda metoda u slucaju
// pokazivaca (*f) u BST::traverseInOrder koje ne dozvoljavaju bocni efekat na ovaj nacin
static void treeToVector(BSTNode* root, std::vector<BSTNode*>& vector){
    if (root){
        treeToVector(root->m_left, vector);
        BSTNode* current = root;
        // dodaje se korijeni cvor + svaki bocno ulancani cvor (duplikat) sa ugradjene jednostruko ulancane liste
        while (current){
            vector.push_back(current);
            current = current->m_next;
        }
        treeToVector(root->m_right, vector);
    }
}

// upisuje cvorove u memoriju sortirane po distanci in-order obilaskom te vraca n-ti najmanji
// npr. getMin(0) vraca najmanji, getMin(1) drugi najmanji itd.
BSTNode* BST::getMin(const int n) const {
    std::vector<BSTNode*> allNodes;
    treeToVector(this->getHead(), allNodes);

    if (allNodes.size() >= n)
        return allNodes[n];
    else 
        return nullptr;
}

// pomocna funkcija za rekurzivnu dealokaciju "zakacenih" duplikata u obliku ulancane liste
static void deleteNodeList(BSTNode* node){
    if (node == nullptr)
        return;
    deleteNodeList(node->m_next);
}

// standardno post-order brisanje sadrzaja koje garantuje brisanje
// svih cvorova redoslijedom koji garantuje da se nece pristupati
// dealociranim cvorovima naknadno
void BST::dispose(){
    traversePostOrder(this->getHead(), [](BSTNode* current){
        deleteNodeList(current);
        delete current;
    });
}

// rekurzivni in-order obilazak uz neku obradu koristeci (*f)
void BST::traverseInOrder(BSTNode* head, void (*f)(BSTNode*)){
    if (head){
        traverseInOrder(head->m_left, f);
        (*f)(head);
        traverseInOrder(head->m_right, f);
    }
}

// rekurzivni post-order obilazak uz neku obradu koristeci (*f)
void BST::traversePostOrder(BSTNode* head, void (*f)(BSTNode*)){
    if (head){
        traversePostOrder(head->m_left, f);
        traversePostOrder(head->m_right, f);
        (*f)(head);
    }
}