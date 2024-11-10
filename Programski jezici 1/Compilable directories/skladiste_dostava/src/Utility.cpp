#include "Utility.h"
#include <bits/stdc++.h>

static bool firstCall = true;
constexpr int letterCount = 26;

static void RandomizeSeed(){
    srand(std::time(0));
}

static char lettersUppercase[letterCount] = 
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// returns an int within [low, high]
int Utility::RandomInt(const int low, const int high){
    // TODO: optimize this lol
    if (firstCall) RandomizeSeed(), firstCall = false;

    if (low < high && low >= 0){
        int num = low + rand() % (high - low + 1);
        return num;
    }
    return -1;
}

// TODO: maybe convert to a strictly uppercase function and add a lowercase one
char Utility::RandomLetter(){
    return lettersUppercase[RandomInt(0, letterCount - 1)];
}