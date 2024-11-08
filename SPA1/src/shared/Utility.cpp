#include "../shared/Utility.h"

// Garancija da svako pokretanje programa nece vratiti istih n rezultata
// pri pozivanju std::rand(); poziva se samo jednom, na pocetku
void Utility::RandomizeSeed(){
    std::srand(std::time(nullptr));
}

// Vraca nasumican (manje vise) broj sa segmenta [low, high]
int Utility::RandomInt(int low, int high){
    int ret = low + (std::rand() % (high - low + 1));
    return ret;
}

// Vraca vektor sa n nasumicnih jedinstvenih elemenata originalnog vektora
std::vector<std::string> Utility::RandomUnique(std::vector<std::string> vector, int n){
    if (n > vector.size())
        return vector;

    auto alreadyContains = [](std::string& string, 
        std::vector<std::string>& vector) -> bool {
        return (std::find(vector.begin(), vector.end(), string) != vector.end());
    };
    
    std::vector<std::string> ret;

    // Indeksira nasumican element pocetnog vektora, te ukoliko se on ne
    // pojavljuje u novom (povratnom), dodaje se na njegov kraj
    while (ret.size() < n){
        int randomIndex = Utility::RandomInt(0, vector.size() - 1);
        std::string current = vector[randomIndex];
        if (!alreadyContains(current, ret))
            ret.push_back(current);
    }

    return ret;
}   