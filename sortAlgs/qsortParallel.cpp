#include <random>
#include <future>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <iostream>
#include "interface.hpp"
using namespace std;

list<int> sortIndex(list<int> input) {
    if (input.empty()) return std::move(list<int>());
    list<int> result;
    result.splice(result.end(), input, input.begin());
    int pivot = *result.begin();
    auto dividePoint = partition(input.begin(), input.end(), 
            [&](const int &i){return i < pivot;});

    list<int> lowPart;
    lowPart.splice(lowPart.end(), input, input.begin(), dividePoint);

    auto lowRes(async(&sortIndex, std::move(lowPart)));
    input = sortIndex(std::move(input));

    result.splice(result.end(), input);
    result.splice(result.begin(), lowRes.get());
    return std::move(result);
}

void sort(vector<int> &array) {
    list<int> input(array.begin(), array.end());
    auto output(sortIndex(input));
    array.assign(output.begin(), output.end());
}

const char *self() {
    return "Quick sort(Parallel)";
}

int main() {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 20);
    auto dice = bind(distribution, generator);

    vector<int> array;
    int num = 10;
    while (num--) 
        array.push_back(dice());
    for(int i: array)
        cout << i << " ";
    sort(array);
    cout << "After:\n";
    for(int i: array)
        cout << i << " ";
    return 0;
}
