#include "Vector.hpp"

Vector::Vector() : m_content(new Complex[m_n]){ }

Vector::Vector(const Vector& other){
    this->m_content = new Complex[Vector::m_n];

    for (int i = 0; i < Vector::m_n; i++)
        this->m_content[i] = other.m_content[i];
}

Vector::Vector(Vector&& other) : m_content(other.m_content){
    other.m_content = nullptr;
}

Vector::~Vector(){
    delete[] this->m_content;
}

void Vector::operator=(const Vector& other){
    for (int i = 0; i < Vector::m_n; i++)
        this->m_content[i] = other.m_content[i];
}

void Vector::operator=(Vector&& other){
    this->m_content = other.m_content;
    other.m_content = nullptr;
}

void Vector::display() const {
    for (int i = 0; i < this->m_n; i++){
        const Complex& current = this->m_content[i];
        std::printf("(%.1lf %.1lf) ", current.getRe(), current.getIm());
    }
    std::cout << std::endl;
}

Complex& Vector::operator[](const int index) const {
    // korektan indeks je odgovornost pozivaoca
    return this->m_content[index];
}

bool Vector::operator==(const Vector& other) const {
    for (int i = 0; i < Vector::m_n; i++)
        if (this->m_content[i] != other.m_content[i])
            return false;
    return true;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this != other);
}

std::ostream& operator<<(std::ostream& stream, const Vector& obj) {
    for (int i = 0; i < obj.m_n; i++){
        const Complex& current = obj.m_content[i];
        stream << "(" << current.getRe() << " " << current.getIm() << ") ";
    }
    stream << std::endl;
    return stream;
}