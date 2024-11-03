#ifndef PACKAGESTACK_H
#define PACKAGESTACK_H

#include "Package.h"
#include <vector>

class PackageStack{
private:
    std::vector<Package> stackVector;
public:
    explicit PackageStack();
    ~PackageStack();

    int getSize();
    Package getTop();
    bool isEmpty();
    void push(const Package package);
    Package pop(bool& success);
};

#endif