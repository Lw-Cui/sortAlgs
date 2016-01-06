#include "merge.hpp"
#include <cstdio>
using namespace std;
void merge(vector<int> &array,
		int left, int mid, int right, vector<int> &tmp) {
	int i = left, j = mid;
	int index = left;

	while (i != mid && j != right)
		if (array[i] < array[j])
			tmp[index++] = array[i++];
		else
			tmp[index++] = array[j++];

	while (i != mid)
		tmp[index++] = array[i++];

	while (j != right)
		tmp[index++] = array[j++];

	for (int p = left; p != right; p++)
		array[p] = tmp[p];
}

void aux(vector<int> &array,
		int left, int right, vector<int> &tmp) {
	if (left >= right - 1)
		return;

	int mid = (left + right) >> 1;
	aux(array, left, mid, tmp);
	aux(array, mid, right, tmp);

	merge(array, left, mid, right, tmp);
}

void sort(vector<int> &array) {
	vector<int> tmp(array);
	aux(array, 0, array.size(), tmp);
}

const char *self() {
	return "Merge sort";
}

/*
int main() {
	int tmp[] = {110, 36, 34, 2, 1};
	vector<int> data(tmp, tmp + sizeof(tmp) / sizeof(int));

	sort(data);
	for (int i = 0; i < data.size(); i++)
		printf("%d ", data[i]);
	return 0;
}
*/
