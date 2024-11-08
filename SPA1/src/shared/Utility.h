#ifndef NAMESPACES_H
#define NAMESPACE_H

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

namespace Utility{
    void RandomizeSeed();
    int RandomInt(int low, int high);

    std::vector<std::string> randomUnique(std::vector<std::string> v, int n);
}

#endif