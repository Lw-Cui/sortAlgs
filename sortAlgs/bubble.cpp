#include "bubble.hpp"
using namespace std;

void sort(std::vector<int> &array) {
    for (size_t i = 0; i < array.size() - 1; i++)
        for (size_t j = 0; j < array.size() - 1 - i; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

const char *self() {
    return "Bubble sort";
}
