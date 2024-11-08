#include "../shared/Utility.h"

void Utility::RandomizeSeed(){
    std::srand(std::time(nullptr));
}

// vraca random (manje vise) broj sa segmenta [low, high]
int Utility::RandomInt(int low, int high){
    int ret = low + (std::rand() % (high - low + 1));
    return ret;
}