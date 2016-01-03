#include "insertion.hpp"
#include <iostream>
using namespace std;

void sort(vector<int> &array) {
    for (size_t i = 1; i < array.size(); i++) {
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

const char *self() {
    return "Insertion sort";
}
