#include "Utility.h"

void Utility::RandomizeSeed(){
    std::srand(std::time(nullptr));
}

// returns a random-ish int from segment [low, high]
int Utility::RandomInt(int low, int high){
    int ret = low + (std::rand() % (high - low + 1));
    return ret;
}