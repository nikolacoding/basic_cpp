#include "Object.hpp"

std::string Object::toString() const {
    return "Object";
}

void Object::print() const {
    std::cout << this->toString() << std::endl;
}

bool Object::equals(const Object& other){
    return this == &other;
}