#include "radix.hpp"
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int getK(vector<int> &array) {
    int max = array[0];
    for (size_t i = 1; i < array.size(); i++)
        if (array[i] > max)
            max = array[i];

    long long p = 10;
    while (max >= p) p *= 10;
    return p / 10;
}

void sort(vector<int> &array) {
    if (array.empty()) return;

    const int R = 10;
    int k = getK(array);
    //printf("k = %d\n", k);
    vector<int> aux(array.size());
    int count[R + 1];

    for (int d = 1; d <= k; d *= 10) {
        memset(count, 0, sizeof(count));

        for (size_t i = 0; i < array.size(); i++)
            count[array[i] / d % 10 + 1]++;

        for (int i = 0; i < R; i++)
            count[i + 1] += count[i];

        for (size_t i = 0; i < array.size(); i++)
            aux[count[array[i] / d % 10]++] = array[i];

        array.assign(aux.begin(), aux.end());
    }
}

const char *self() {
    return "Radix sort";
}

/*
int main() {
    int tmp[] = {1, 34, 123, 54, 2, 1000000};
    vector<int> data(tmp, tmp + 6);

    sort(data);

    for (int i = 0; i < data.size(); i++)
        printf("%d ", data[i]);
    return 0;
}
*/
