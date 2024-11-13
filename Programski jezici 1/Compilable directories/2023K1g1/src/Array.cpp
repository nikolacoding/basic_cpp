#include "Array.hpp"

Array::Array(int initCapacity) :
    m_capacity(initCapacity), m_size(0), m_array(new Vector2D[initCapacity]) {

}

Array::Array(const Array& other){
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;

    for (int i = 0; i < other.m_size; i++){
        this->m_array[i] = other.m_array[i];
    }
    // delete[] other.m_array;       [mozda?]
}

// Array::~Array(){
//     delete[] this->m_array;
// }

void Array::append(const Vector2D& vector){
    if (this->m_size == this->m_capacity)
        this->realloc(this->m_capacity * 2);
    
    this->m_array[m_size++] = vector;
}

int Array::getSize() const {
    return this->m_size;
}

Vector2D& Array::at(const int index, bool& success){
    if (index >= this->m_size){
        success = false;
        return Vector2D::invalidVector;
    }
    
    success = true;
    return this->m_array[index];
}

const Vector2D& Array::at(const int index, bool& success) const {
    if (index >= this->m_size){
        success = false;
        return Vector2D::invalidVector;
    }
    
    success = true;
    return this->m_array[index];
}

void Array::displayAll(){
    for (int i = 0; i < this->m_size; i++){
        std::cout << this->m_array[i].getX() << ", " << this->m_array[i].getY() << std::endl;
    }
    std::cout << std::endl;
}

void Array::realloc(const int newCapacity){
    Vector2D* newArray = new Vector2D[newCapacity];
    for (int i = 0; i < this->m_capacity; i++)
        newArray[i] = this->m_array[i];
    
    delete[] this->m_array;
    this->m_array = newArray;
}