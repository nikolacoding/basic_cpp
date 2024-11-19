#include <iostream>
#include "Matrix.hpp"

//  n = 3, m = 4
//
//  1   1   2   2
//  3   3   4   4
//  5   5   6   6
// 

int main(void){
    Matrix m(3, 3);

#pragma region decl
    m.m_content[0] = 1;
    m.m_content[1] = 2;
    m.m_content[2] = 3;

    m.m_content[3] = 4;
    m.m_content[4] = 5;
    m.m_content[5] = 6;

    m.m_content[6] = 7;
    m.m_content[7] = 8;
    m.m_content[8] = 9;

#pragma endregion

    Matrix m2 = m;
    Matrix m3 = m + m2;
    Matrix m4 = m3.transform([](double d){
        return d * 5;
    });

    m4 *= m;
    
    m4.displayAll();
}   