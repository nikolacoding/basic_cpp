#include "Vector2DArray.h"

Vector2DArray::Vector2DArray(int capacity) : 
m_capacity(capacity), m_size(0){
    if (capacity <= 0){
        capacity = 0;
        m_vectors = nullptr;
    }
    else{
        m_vectors = new Vector2D[capacity];
    }
}

Vector2DArray::~Vector2DArray(){
    delete[] m_vectors;
}

int Vector2DArray::getCapacity() const {
    return this->m_capacity;
}

int Vector2DArray::getSize() const {
    return this->m_size;
}

void Vector2DArray::append(const Vector2D& vector){
    if (this->m_size >= this->m_capacity)
        realloc(true);
    this->m_vectors[this->m_size++] = vector;
}

void Vector2DArray::remove(int index){
    if (this->isValidIndex(index)){
        for (int i = index; i < this->m_size - 1; i++){
            this->m_vectors[i] = this->m_vectors[i + 1];
        }
        this->m_size--;
    }

    if (this->m_size <= this->m_capacity / 2){
        realloc(false);
    }
}

Vector2D& Vector2DArray::at(int index, bool& success){
    if (this->isValidIndex(index)){
        success = true;
        return this->m_vectors[index];
    }
    success = false;
    return Vector2D::invalidVector;
}

const Vector2D& Vector2DArray::at(int index, bool& success) const {
    if (index < this->m_size){
        success = true;
        return this->m_vectors[index];
    }
}

void Vector2DArray::forEach(void (*f)(Vector2D&)){
    for (int i = 0; i < this->m_size; i++){
        (*f)(this->m_vectors[i]);
    }
}

void Vector2DArray::forEach(void (*f)(const Vector2D&)) const {
    for (int i = 0; i < this->m_size; i++){
        (*f)(this->m_vectors[i]);
    }
}

void Vector2DArray::realloc(bool up){
    realloc(this->m_capacity <= 0 ? 1 : (up ? this->m_capacity * 2 : this->m_capacity / 2));
}

void Vector2DArray::realloc(int newCapacity){
    std::printf("Changed the capacity and allocated space from %d to %d.\n", this->m_capacity, newCapacity);

    this->m_capacity = newCapacity;
    Vector2D* newArray = new Vector2D[newCapacity];
    for (int i = 0; i < this->m_size; i++){
        newArray[i] = this->m_vectors[i];
    }
    delete[] this->m_vectors;
    this->m_vectors = newArray;
}

bool Vector2DArray::isValidIndex(int index) const {
    // da li je indeks na segmentu [0, n)
    return (index >= 0 && index < this->m_size);
}