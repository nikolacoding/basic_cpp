#include "Utility.h"

auto calcFact = [](int n) -> int {
    int r = n;
    for (int i = n - 1; i > 0; i--)
        r *= i;
    
    return r;
};

void Utility::factorial(int& val){
    val = calcFact(val);
}

void Utility::factorial(int& val1, int& val2){
    val1 = calcFact(val1);
    val2 = calcFact(val2);
}