#ifndef PACKAGESTACK_H
#define PACKAGESTACK_H

#include "Package.h"

class PackageStack{
private:
    const int _capacity;
    Package* _packageArray;
    int _topIndex;
public:
    explicit PackageStack(int capacity = 5);
    ~PackageStack();

    int getSize();
    bool isEmpty();
    void push(Package package);
    Package& pop();
};

#endif