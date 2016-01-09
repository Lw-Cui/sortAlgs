#include "heap.hpp"
using namespace std;

int left(int pos) {
    return pos * 2 + 1;
}

int right(int pos) {
    return pos * 2 + 2;
}

void push_down(vector<int> &array, int end, int pos) {
	while (left(pos) < end) {
		int next = left(pos);
		if (next + 1 < end && array[next] < array[next + 1])
			next++;
		if (array[next] <= array[pos])
			break;
		swap(array[next], array[pos]);
		pos = next;
	}
}

void sort(vector<int> &array) {
    for (int i = array.size() / 2; i >= 0; i--)
        push_down(array, array.size(), i);

    for (int i = array.size() - 1; i > 0; i--) {
        swap(array[i], array[0]);
        push_down(array, i, 0);
    }
}

const char *self() {
    return "Heap sort";
}
