# Sorting Laboratory #

## Introduction ##
This is a tiny project assigned by `Data structure and algorithm` course at `Harbin Institute of Technology`. We were asked to complement some sorting algorithms including `quick sort`, `heap sort`, `selection sort` and so on. Performance comparson is preferred.

## Feature ##
To make the program scalable I use `shared object` file to implement algorithm. Any algs implementing the interface should work with this program without issue:
```
void sort(std::vector<int> &);
const char *self();
```
The first implement algs while the second show its info.

## Usage ##
* In subdirectory `sortAlgs` of this repository please execute `make` command.

```
lw@lw-ThinkPad-T420:~/sortingLab/sortAlgs$ make
g++ bubble.cpp -o bubble.o -Wall -c
g++ bubble.o -o bubble.so -shared -fPIC
g++ heap.cpp -o heap.o -Wall -c
g++ heap.o -o heap.so -shared -fPIC
g++ insertion.cpp -o insertion.o -Wall -c
g++ insertion.o -o insertion.so -shared -fPIC
g++ qsort.cpp -o qsort.o -Wall -c
g++ qsort.o -o qsort.so -shared -fPIC
g++ radix.cpp -o radix.o -Wall -c
g++ radix.o -o radix.so -shared -fPIC
for so in  bubble.so  heap.so  insertion.so  qsort.so  radix.so; do sudo cp $so /usr/lib; done
```
*Yeah you should be granted `sudo` privilege.*


* Then in the root directory of this repo you could type(or just run the `run.sh` directly):
```
g++ SortCompare.cpp -ldl -g -o SortCompare.out
./SortCompare.out insertion.so qsort.so heap.so bubble.so radix.so

``` 
Here you could replace those *.so with library you choose.

 * Result
```
For 1000 integers
    Quick sort is 1.73 times faster than Heap sort
    Heap sort is 1.00 times faster than Radix sort
    Radix sort is 6.82 times faster than Insertion sort
    Insertion sort is 3.62 times faster than Bubble sort

For 3000 integers
    Quick sort is 1.49 times faster than Radix sort
    Radix sort is 1.22 times faster than Heap sort
    Heap sort is 16.77 times faster than Insertion sort
    Insertion sort is 3.81 times faster than Bubble sort

For 5000 integers
    Quick sort is 1.45 times faster than Radix sort
    Radix sort is 1.30 times faster than Heap sort
    Heap sort is 25.94 times faster than Insertion sort
    Insertion sort is 3.85 times faster than Bubble sort

For 7000 integers
    Quick sort is 1.37 times faster than Radix sort
    Radix sort is 1.35 times faster than Heap sort
    Heap sort is 35.01 times faster than Insertion sort
    Insertion sort is 3.90 times faster than Bubble sort

For 9000 integers
    Quick sort is 1.29 times faster than Radix sort
    Radix sort is 1.44 times faster than Heap sort
    Heap sort is 43.93 times faster than Insertion sort
    Insertion sort is 3.85 times faster than Bubble sort

```
