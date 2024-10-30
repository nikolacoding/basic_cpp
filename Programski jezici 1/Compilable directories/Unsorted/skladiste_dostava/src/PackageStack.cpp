#include "PackageStack.h"

PackageStack::PackageStack(int capacity = 5) : 
                            _capacity(capacity), _packageArray(new Package[capacity]), _topIndex(-1) {

}

PackageStack::~PackageStack(){
    delete[] _packageArray;
}

int PackageStack::getSize(){
    return this->_topIndex + 1;
}

bool PackageStack::isEmpty(){
    return this->_topIndex == -1;
}

void PackageStack::push(Package package){
    if (this->getSize() != this->_capacity){
        // kopija
    }
}

Package& PackageStack::pop(){
    if (!this->isEmpty()){
        return this->_packageArray[_topIndex--];
    }
}