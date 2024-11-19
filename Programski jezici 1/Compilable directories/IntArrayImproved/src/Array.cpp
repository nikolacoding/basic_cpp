#include "Array.hpp"

Array operator*(const Array& array, const int quotient) {
    Array newArray = array;
    for (int i = 0; i < array.m_size; i++){
        newArray[i] = array[i] * quotient;
    }
    return newArray;
}

Array operator*(const int quotient, const Array& array) { return array * quotient; }

std::ostream& operator<<(std::ostream& ostream, const Array& array) {
    for (int i = 0; i < array.m_size; i++)
        ostream << array[i] << " ";
    ostream << std::endl;
    
    return ostream;
}

std::istream& operator>>(std::istream& istream, Array& array) {
    int n;
    std::cout << "Unesi broj clanova: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        int current;
        istream >> current;
        array += current;
    }

    return istream;
}

Array::Array(int initCapacity) : 
    m_capacity(initCapacity), m_size(0), m_data(new int[initCapacity]) { }

Array::Array(const Array& other) : 
    m_capacity(other.m_capacity), m_size(other.m_size), m_data(new int[m_capacity]) {
    
    for (int i = 0; i < other.m_size; i++)
        m_data[i] = other.m_data[i];
}

void Array::displayAll() const {
    for (int i = 0; i < this->m_size; i++)
        std::printf("%d ", this->m_data[i]);
    std::printf("\n");
}

void Array::append(const int value){
    if (this->m_capacity == 0)
        this->realloc(1);

    if (this->isFull())
        this->realloc(this->m_capacity * 2);
    
    this->m_data[this->m_size++] = value;
}

bool Array::pop(int& value){
    if (this->isEmpty())
        return false;
    
    value = this->m_data[--this->m_size];

    if (this->m_size <= this->m_capacity / 2)
        this->realloc(this->m_capacity / 2);

    return true;
}

// validnost indeksa se ostavlja kao obaveza pozivaoca
int& Array::at(const int index) const {
    return this->m_data[index];
}

Array Array::filter(bool (*condition)(const int)) const {
    Array newArray;

    for (int i = 0; i < this->m_size; i++){
        int current = (*this)[i];
        if ((*condition)(current)){
            newArray += current;
        }
    }

    return newArray;
}

Array Array::transform(int (*tr)(const int)) const {
    Array newArray = *this;

    for (int i = 0; i < this->m_size; i++)
        newArray[i] = (*tr)((*this)[i]);
    
    return newArray;
}

Array Array::operator+(const int value) const {
    Array newArray = *this;
    newArray.append(value);
    return newArray;
}

void Array::operator+=(const int value) {
    this->append(value);
}

Array Array::operator+(const Array& other) const {
    int iterations = (this->m_size < other.m_size) ? this->m_size : other.m_size;

    Array newArray = *this;
    for (int i = 0; i < iterations; i++){
        newArray.at(i) += other.at(i);
    }

    return newArray;
}

void Array::operator+=(const Array& other) {
    int iterations = (this->m_size < other.m_size) ? this->m_size : other.m_size;

    for (int i = 0; i < iterations; i++){
        (*this)[i] += other[i];
    }
}

int& Array::operator[](const int index) const {
    return this->at(index);
}

bool Array::operator==(const Array& other) const {
    if (this->m_size != other.m_size)
        return false;
    
    for (int i = 0; i < this->m_size; i++){
        if ((*this)[i] != other[i])
            return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

bool Array::operator>(const Array& other) const {
    return this->m_size > other.m_size;
}

bool Array::operator>=(const Array& other) const {
    return this->m_size >= other.m_size;
}

bool Array::operator<(const Array& other) const {
    return this->m_size < other.m_size;
}

bool Array::operator<=(const Array& other) const {
    return this->m_size <= other.m_size;
}

inline bool Array::isFull(){
    return this->m_size == this->m_capacity;
}

inline bool Array::isEmpty(){
    return this->m_size == 0;
}

// odvratno ali brzinski
static void clamp(bool updown, int& num, const int limit){
    if (!updown){
        if (num > limit)
            num = limit;
    }
    else{
        if (num < limit)
            num = limit;
    }
}
// [from, to)
void Array::operator()(int from, int to, void (*f)(int&)) {
    clamp(true, from, 0);
    clamp(false, to, this->m_size);

    for (int i = from; i < to; i++){
        (*f)((*this)[i]);
    }
}

void Array::operator()(void (*f)(int&)) {
    (*this)(0, this->m_size, f);
}

void Array::realloc(int newCapacity){
    this->m_capacity = newCapacity;
    int* newArray = new int[newCapacity];
    for (int i = 0; i < this->m_size; i++)
        newArray[i] = this->m_data[i];
    
    delete[] this->m_data;
    this->m_data = newArray;
}