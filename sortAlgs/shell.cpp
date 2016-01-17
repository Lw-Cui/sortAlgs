#include "shell.hpp"
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

int main() {
	int data[] = {3, 2, 1, 5, 1, 2, 6, 7, 3, 7, 11, 12};
	vector<int> a(data, data + sizeof(data) / sizeof(int));
	sort(a);
	for (int i = 0; i < a.size(); i++)
		printf("%d ", a[i]);
	return 0;
}
