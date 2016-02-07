#include "interface.hpp"
#include <cstdio>
using namespace std;

void aux_sort(vector<int> &array, int left, int right) {
	if (left >= right - 1)
		return;

	int pivot = array[left];
	int lt = left, gt = right - 1;
	int i = left + 1;
	while (i <= gt) {
		if (array[i] < pivot)
			swap(array[i++], array[lt++]);
		else if (array[i] > pivot)
			swap(array[i], array[gt--]);
		else
			i++;
	}

	aux_sort(array, left, lt);
	aux_sort(array, gt + 1, right);
}

void sort(vector<int> &array) {
	aux_sort(array, 0, array.size());
}

const char *self() {
	return "Qsort(3 way)";
}

/*
int main() {
	int tmp[] = {3, 23, 2, 1, 1, 1, 1, 45, 3, 3};
	vector<int> data(tmp, tmp + sizeof(tmp) / sizeof(int));
	sort(data);
	for (int i = 0; i < data.size(); i++)
		printf("%d ", data[i]);
	return 0;
}
*/
