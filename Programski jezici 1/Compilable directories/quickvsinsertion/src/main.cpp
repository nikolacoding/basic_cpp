#include <iostream>
#include <vector>
using std::vector;

#include <ctime>
#include <chrono>
#include "Algorithms.hpp"

int main(void){
    std::srand(std::time(0));

    auto measure_is = [](std::vector<int>& v) -> double {
        auto t1 = std::chrono::high_resolution_clock::now();
        Algorithms::insertionSort(v);
        auto t2 = std::chrono::high_resolution_clock::now();

        double difference = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1).count();

        return difference;
    };

    auto measure_qs = [](std::vector<int>& v) -> double {
        auto t1 = std::chrono::high_resolution_clock::now();
        Algorithms::quickSort(v, 0, v.size() - 1);
        auto t2 = std::chrono::high_resolution_clock::now();

        double difference = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1).count();

        return difference;
    };

    auto logBoth = [](int nums, double is, double qs) -> void {
        std::printf("[%d] IS: %.4lfms, QS: %.4lfms\n", nums, is, qs);
    };

    auto vSmall1 = Algorithms::randVect(20);    auto vSmall2 = vSmall1;
    auto vSmall3 = Algorithms::randVect(50);    auto vSmall4 = vSmall3;
    auto vSmall5 = Algorithms::randVect(100);   auto vSmall6 = vSmall5;
    auto vSmall7 = Algorithms::randVect(200);   auto vSmall8 = vSmall7;
    auto vSmall9 = Algorithms::randVect(500);   auto vSmall10 = vSmall9;
    auto vSmall11 = Algorithms::randVect(1000);  auto vSmall12 = vSmall11;

    double v20is = measure_is(vSmall1);
    double v20qs = measure_qs(vSmall2);

    double v50is = measure_is(vSmall3);
    double v50qs = measure_qs(vSmall4);

    double v100is = measure_is(vSmall5);
    double v100qs = measure_qs(vSmall6);

    double v200is = measure_is(vSmall7);
    double v200qs = measure_qs(vSmall8);

    double v500is = measure_is(vSmall9);
    double v500qs = measure_qs(vSmall10);

    double v1000is = measure_is(vSmall11);
    double v1000qs = measure_qs(vSmall12);

    logBoth(20, v20is, v20qs);
    logBoth(50, v50is, v50qs);
    logBoth(100, v100is, v100qs);
    logBoth(200, v200is, v200qs);
    logBoth(500, v500is, v500qs);
    logBoth(1000, v1000is, v1000qs);
}