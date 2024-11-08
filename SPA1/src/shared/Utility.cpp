#include "../shared/Utility.h"

void Utility::RandomizeSeed(){
    std::srand(std::time(nullptr));
}

// vraca random (manje vise) broj sa segmenta [low, high]
int Utility::RandomInt(int low, int high){
    int ret = low + (std::rand() % (high - low + 1));
    return ret;
}

// vraca vektor sa n nasumicnih jedinstvenih elemenata originalnog vektora
std::vector<std::string> Utility::randomUnique(std::vector<std::string> vector, int n){
    auto rd = std::random_device { };
    auto seed = std::default_random_engine { rd() };
    std::shuffle(std::begin(vector), std::end(vector), seed);

    std::vector<std::string> ret;
    // sa losim argumentima lako moze nastati segfault
    for (int i = 0; i < n; i++){
        ret.push_back(vector[i]);
    }

    return ret;
}   