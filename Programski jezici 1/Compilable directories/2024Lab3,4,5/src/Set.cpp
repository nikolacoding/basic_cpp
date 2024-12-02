#include "Set.hpp"

Set::Set(int initCapacity) : m_capacity(initCapacity), m_size(0), m_vectors(new Vector[initCapacity]) {

}

Set::Set(const Set& other) : m_capacity(other.m_capacity), m_size(other.m_size){
    delete[] this->m_vectors;
    this->m_vectors = new Vector[m_capacity];
    
    for (int i = 0; i < this->m_size; i++)
        this->m_vectors[i] = other.m_vectors[i];

}

Set::Set(Set&& other) : m_capacity(other.m_capacity), m_size(other.m_size), m_vectors(other.m_vectors){
    other.m_vectors = nullptr;
}

Set::~Set(){
    delete[] this->m_vectors;
}

Set& Set::operator=(const Set& other){
    if (this != &other){
        delete[] this->m_vectors;
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        this->m_vectors = new Vector[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
            this->m_vectors[i] = other.m_vectors[i];
    }
    return *this;
}

Set& Set::operator=(Set&& other){
    if (this != &other){
        delete[] this->m_vectors;

        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        this->m_vectors = other.m_vectors;
        
        other.m_vectors = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    return *this;
} 

void Set::add(const Vector& vector){
    if (this->isFull())
        this->realloc(this->m_capacity * 2);
    
    this->m_vectors[this->m_size++] = vector;
}

bool Set::equals(const Set& other){
    if (this->getSize() != other.getSize())
        return false;

    for (int i = 0; i < this->getSize(); i++){
        if (this->m_vectors[i] != other.m_vectors[i])
            return false;
    }
    return true;
}

void Set::operator+=(const Vector& vector){
    this->add(vector);
}

bool Set::operator==(const Set& other){
    return ((*this).equals(other));
}

Set Set::operator+(const Set& other) const {
    Set base = *this;
    for (int i = 0; i < other.getSize(); i++)
        base += other.m_vectors[i];
    return base;
}

std::ostream& operator<<(std::ostream& stream, const Set& obj) {
    for (int i = 0; i < obj.getSize(); i++)
        stream << obj.m_vectors[i];
    stream << std::endl;   
    return stream;
}

void Set::realloc(int newCapacity){
    this->m_capacity = newCapacity;
    Vector* newArray = new Vector[newCapacity];

    for (int i = 0; i < this->getSize(); i++)
        newArray[i] = this->m_vectors[i];
    
    delete[] this->m_vectors;
    this->m_vectors = newArray;
}

void Set::displayAll() const {
    for (int i = 0; i < this->getSize(); i++)
        this->m_vectors[i].display();
    std::cout << std::endl;
}