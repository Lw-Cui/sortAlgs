#include "interface.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
void sort(vector<int> &array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
		int smallest = i;
		for (size_t pos = i; pos < array.size(); pos++)
			if (array[pos] < array[smallest])
				smallest = pos;
		swap(array[smallest], array[i]);
    }
}

const char *self() {
    return "Selection sort";
}
