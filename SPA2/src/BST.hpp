#ifndef BST_H
#define BST_H

#include "BSTNode.hpp"

class BST final {
private:
    BSTNode* m_head;

public:
    BST(BSTNode* head = nullptr) : m_head(head) {}
    ~BST();
    
    void insert(BSTNode* const node);
    void operator+=(BSTNode* const node);

    BSTNode* find(const int distance) const;
    BSTNode* getHead() const { return this->m_head; }
    BSTNode* getMin(const int n) const;

    // razlog za staticku implementaciju je rekurzivna priroda funkcije koja ne bi mogla biti metoda koja
    // radi sa samom instancom trenutnog objekta BST-a
    static void traverseInOrder(BSTNode* head, void (*f)(BSTNode*));
    static void traversePostOrder(BSTNode* head, void (*f)(BSTNode*));

private:
    void dispose();
};

#endif