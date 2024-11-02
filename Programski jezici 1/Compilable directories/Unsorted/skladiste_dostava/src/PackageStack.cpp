#include "PackageStack.h"

PackageStack::PackageStack(){

}

PackageStack::~PackageStack(){

}

int PackageStack::getSize(){
    return this->stackVector.size();
}

bool PackageStack::isEmpty(){
    return this->stackVector.empty();
}

void PackageStack::push(const Package package){
    this->stackVector.push_back(package);
}

Package PackageStack::pop(bool& success){
    if (this->isEmpty()){
        success = false;
        return Package::emptyPackage;
    }
    success = true;
    Package ret = this->stackVector.back();
    stackVector.pop_back();
    return ret;
}