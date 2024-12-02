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
    Matrix(Matrix&& other);
    //~Matrix();

    void displayAll() const;

    void setValue(const int m, const int n, const double value);
    Matrix transform(double (*f)(double)) const;

    // dodjela
    void operator=(const Matrix& other);
    void operator=(Matrix&& other);

    // sabiranje
    Matrix operator+(const Matrix& other) const;
    void operator+=(const Matrix& other);

    // mnozenje
    Matrix operator*(const Matrix& other) const;
    void operator*=(const Matrix& other);

    // mnozenje skalarom
    Matrix operator*(const double quotient) const;
    void operator*=(const double quotient);

    // jednakost
    bool operator==(const Matrix& other) const;

    // indeksiranje
    double* operator[](const int index) const;
    double& operator()(int i, int j) const;

    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& stream, Matrix& matrix);

    // TODO:
    // 4. jedinicna staticka matrica
};

#endif