#include "Matrix.hpp"

Matrix::Matrix(int nInit, int mInit) : 
    m_n(nInit), m_m(mInit), m_content(new double[m_m * m_n]) {
    
    for (int i = 0; i < this->totalSize(); i++)
        this->m_content[i] = 0;
}

Matrix::Matrix(const Matrix& other) : 
    m_m(other.m_m), m_n(other.m_n), m_content(new double[m_n * m_m]) {
    
    for (int i = 0; i < this->m_m * this->m_n; i++)
        this->m_content[i] = other.m_content[i];
}

Matrix::Matrix(Matrix&& other) : m_m(other.m_m), m_n(other.m_n), m_content(other.m_content) {
    other.m_content = nullptr;
}

int Matrix::totalSize() const {
    return this->m_m * this->m_n;
}

void Matrix::displayAll() const {
    for (int i = 0; i < this->m_n; i++){
        for (int j = 0; j < this->m_m; j++){
            std::printf("%4.1lf      ", this->m_content[i * this->m_m + j]);
        }
        std::printf("\n");
    }
}

void Matrix::setValue(const int m, const int n, const double value){
    this->m_content[n * this->m_m + m] = value;
}

Matrix Matrix::transform(double (*f)(double)) const {
    Matrix newMatrix(this->m_n, this->m_m);

    for (int i = 0; i < newMatrix.totalSize(); i++)
        newMatrix.m_content[i] = (*f)(this->m_content[i]);

    return newMatrix;
}

void Matrix::operator=(const Matrix& other){
    if (this != &other){
        std::cout << "a\n";
        this->m_m = other.m_m;
        this->m_n = other.m_n;
        for (int i = 0; i < this->totalSize(); i++)
            this->m_content[i] = other.m_content[i];
    }
}

void Matrix::operator=(Matrix&& other){
    std::cout << "b\n";
    this->m_m = other.m_m;
    this->m_n = other.m_n;
    this->m_content = other.m_content;
    other.m_content = nullptr;
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

Matrix Matrix::operator*(const Matrix& other) const {
    const Matrix& m1 = *this;
    const Matrix& m2 = other;
    Matrix newMatrix(m1.m_m, m2.m_n);
    // row - m
    // col - n
    for (int i = 0; i < m1.m_m; i++){
        for (int j = 0; j < m2.m_n; j++){
            int sum = 0;
            for (int k = 0; k < m1.m_n; k++){
                newMatrix.m_content[i * newMatrix.m_n + j] += m1.m_content[i * m1.m_n + k] * m2.m_content[k * m2.m_n + j];
            }
        }
    }
    return newMatrix;
}

void Matrix::operator*=(const Matrix& other) {
    Matrix m1(*this);
    const Matrix& m2 = other;

    for (int i = 0; i < this->totalSize(); i++)
        this->m_content[i] = 0;

    for (int i = 0; i < m1.m_m; i++){
        for (int j = 0; j < m2.m_n; j++){
            int sum = 0;
            for (int k = 0; k < m1.m_n; k++){
                this->m_content[i * m1.m_n + j] += m1.m_content[i * m1.m_n + k] * m2.m_content[k * m2.m_n + j];
            }
        }
    }
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

double& Matrix::operator()(int i, int j) const {
    return this->m_content[i * this->m_m + j];
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
    for (int i = 0; i < matrix.m_n; i++){
        for (int j = 0; j < matrix.m_m; j++){
            stream << "      " << matrix.m_content[i * matrix.m_m + j];
        }
        stream << std::endl;
    }   
    return stream;
}

// pretpostavlja se da su instanci matrice vec dodijeljene validne vrijednosti
std::istream& operator>>(std::istream& stream, Matrix& matrix) {
    for (int i = 0; i < matrix.totalSize(); i++){
        stream >> matrix.m_content[i];
    }
    return stream;
}