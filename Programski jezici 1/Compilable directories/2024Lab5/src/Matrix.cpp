#include "Matrix.hpp"

Matrix::Matrix(int nInit, int mInit) : 
    m_n(nInit), m_m(mInit), m_content(new double[m_m * m_n]) {
    

}

Matrix::Matrix(const Matrix& other) : 
    m_m(other.m_m), m_n(other.m_n), m_content(new double[m_n * m_m]) {
    
    for (int i = 0; i < this->m_m * this->m_n; i++)
        this->m_content[i] = other.m_content[i];
}

int Matrix::totalSize() const {
    return this->m_m * this->m_n;
}

//  n = 3, m = 4
//
//  1   1   2   2
//  3   3   4   4
//  5   5   6   6
// 

void Matrix::setValue(const int m, const int n, const double value){
    this->m_content[n * this->m_m + m] = value;
}

void Matrix::displayAll() const {
    for (int i = 0; i < this->m_n; i++){
        for (int j = 0; j < this->m_m; j++){
            std::printf("%4.1lf      ", this->m_content[i * this->m_m + j]);
        }
        std::printf("\n");
    }
}
// #############
// # Operatori #
// #############

Matrix Matrix::operator+(const Matrix& other) const {
    // TODO: vratiti jedinicnu matricu ako nisu kompatibilne za sabiranje

    Matrix newMatrix(*this);
    for (int i = 0; i < this->totalSize(); i++)
        newMatrix.m_content[i] += other.m_content[i];

    return newMatrix;
}

void Matrix::operator+=(const Matrix& other){
    if (this->totalSize() != other.totalSize())
        return;
    
    for (int i = 0; i < this->totalSize(); i++)
        this->m_content[i] += other.m_content[i];
}

void Matrix::operator*=(const double quotient){
    for (int i = 0; i < this->totalSize(); i++)
        this->m_content[i] *= quotient;
}

Matrix Matrix::operator*(const double quotient) const {
    Matrix newMatrix(*this);
    for (int i = 0; i < this->totalSize(); i++){
        newMatrix.m_content[i] *= quotient;
    }
    return newMatrix;
}

bool Matrix::operator==(const Matrix& other) const {
    if (this->totalSize() != other.totalSize())
        return false;

    for (int i = 0; i < this->totalSize(); i++){
        if (this->m_content[i] != other.m_content[i])
            return false;
    }

    return true;
}

double* Matrix::operator[](const int index) const {
    if (index >= this->m_n)
        return nullptr;

    int size = this->m_m;
    double* ret = new double[size];

    for (int i = 0; i < size; i++)
        ret[i] = this->m_content[index * size + i];

    return ret;
}