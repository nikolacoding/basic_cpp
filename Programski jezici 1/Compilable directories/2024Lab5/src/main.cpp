#include <iostream>
#include "Matrix.hpp"

//  n = 3, m = 4
//
//  1   1   2   2
//  3   3   4   4
//  5   5   6   6
// 

int main(void){
    Matrix m(3, 4);

#pragma region decl
    m.m_content[0] = 1;
    m.m_content[1] = 1;
    m.m_content[2] = 2;
    m.m_content[3] = 2;

    m.m_content[4] = 3;
    m.m_content[5] = 3;
    m.m_content[6] = 4;
    m.m_content[7] = 4;

    m.m_content[8] = 5;
    m.m_content[9] = 5;
    m.m_content[10] = 6;
    m.m_content[11] = 6;
#pragma endregion

    Matrix m2 = m;
    Matrix m3 = m + m2;

    std::cout << "test: " << m[2][3] << std::endl;
    
    // m3.displayAll();
}   