#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <vector>

namespace Algorithms{

    void insertionSort(std::vector<int>& vec) {
        for (int i = 1; i < vec.size(); i++) {
            int key = vec[i];
            int j = i - 1;

            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = key;
        }
    }

    static int partition(std::vector<int>& vec, int low, int high) {
        int pivot = vec[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (vec[j] <= pivot) {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[high]);
        return i + 1;
    }

    void quickSort(std::vector<int>& vec, int low, int high) {
        if (low < high) {
            int pi = partition(vec, low, high);

            quickSort(vec, low, pi - 1);
            quickSort(vec, pi + 1, high);
        }
    }

    std::vector<int> randVect(int n) {
        std::vector<int> result;
        result.reserve(n);

        std::srand(std::time(0));

        for (int i = 0; i < n; ++i) {
            int randomNum = (std::rand() % 2001) - 1000;
            result.push_back(randomNum);
        }

        return result;
    }
}

#endif