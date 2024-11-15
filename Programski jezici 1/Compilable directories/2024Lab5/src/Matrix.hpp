#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
private:
    int m_m, m_n;
    double* m_content;

private:
    int totalSize() const;
    friend int main();

public:
    Matrix(int nInit = 2, int mInit = 2);
    Matrix(const Matrix& other);
    //~Matrix();

    void setValue(const int m, const int n, const double value);
    void displayAll() const;

    // sabiranje
    Matrix operator+(const Matrix& other) const;
    void operator+=(const Matrix& other);

    // mnozenje skalarom
    Matrix operator*(const double quotient) const;
    void operator*=(const double quotient);

    // jednakost
    bool operator==(const Matrix& other) const;

    // indeksiranje
    double* operator[](const int index) const;

    // TODO:
    // 1. mnozenje
    // 2. ispis na izlaz
    // 3. unos sa ulaza
    // 4. jedinicna staticka matrica
    // 5. cista transform metoda
};

#endif