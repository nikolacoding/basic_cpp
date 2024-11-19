#include <iostream>
#include "Array.hpp"

int main(){
    Array a;
    std::cin >> a;
    Array b = a;

    b(0, INT_MAX, [](int& current){
        current *= 2;
    });

    Array c = b.transform([](const int n){
        return n * 15;
    });

    Array d = c.filter([](const int n){
        return n < 100;
    });

    std::cout << a;
    std::cout << b;
    std::cout << c;
    std::cout << d;
}