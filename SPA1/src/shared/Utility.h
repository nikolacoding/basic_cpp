#ifndef NAMESPACES_H
#define NAMESPACE_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

namespace Utility{
    void RandomizeSeed();
    int RandomInt(int low, int high);

    std::vector<std::string> RandomUnique(std::vector<std::string> v, int n);
}

#endif