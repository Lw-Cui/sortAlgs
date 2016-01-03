#include <iostream>
#include "qsort.hpp"
using namespace std;

void sortIndex(vector<int> &array, int left, int right) {
    if (left >= right - 1)
        return;

    int divide_pos = left;

    for (int i = left + 1; i < right; i++)
        if (array[i] < array[left])
            swap(array[i], array[++divide_pos]);
    swap(array[divide_pos], array[left]);

    sortIndex(array, left, divide_pos);
    sortIndex(array, divide_pos + 1, right);
}

void sort(vector<int> &array) {
    sortIndex(array, 0, array.size());
}
