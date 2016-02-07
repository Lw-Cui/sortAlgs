#include "interface.hpp"
#include <cstdio>
using namespace std;

void sort(std::vector<int> &array) {
	size_t h = 1;
	while (h < array.size() / 9) h = h * 3 + 1;

	for (; h > 0; h /= 3)
		for (size_t i = h; i < array.size(); i++) {
			size_t j = i;
			int tmp = array[i];

			while (j >= h && array[j - h] > tmp) {
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = tmp;
		}
}

const char *self() {
	return "Shell sort";
}

