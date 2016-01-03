# Sorting Laboratory #

## Introduction ##
This is a tiny project assigned by `Data structure and algorithm` course at `Harbin Institute of Technology`. We were asked to complement some sorting algorithms including `quick sort`, `heap sort`, `selection sort` and so on. Performance comparson is preferred.

## Feature ##
To make the program scalable I use `shared object` file to implement algorithm. Any algs implementing the interface should work with this program without issue.

## Usage ##
* In subdirectory `sortAlgs` of this repository please execute `make` command.

```
lw@lw-ThinkPad-T420:~/sortingLab/sortAlgs$ make
g++ heap.cpp -o heap.o -Wall -c
g++ heap.o -o heap.so -shared -fPIC
g++ insertion.cpp -o insertion.o -Wall -c
g++ insertion.o -o insertion.so -shared -fPIC
g++ qsort.cpp -o qsort.o -Wall -c
g++ qsort.o -o qsort.so -shared -fPIC
for so in  heap.so  insertion.so  qsort.so; do sudo cp $so /usr/lib; done
```
*Yeah you should be granted `sudo` privilege.*


* Then in the root directory of this repo you could type(or just run the `run.sh` directly):
```
 g++ SortCompare.cpp -ldl -g -o SortCompare.out
./SortCompare.out insertion.so qsort.so heap.so
``` 
Here you could replace those *.so with library you choose.

 * Result
```
For 10000 integers
    Quick sort is 1.87 times faster than Heap sort
    Heap sort is 47.92 times faster than Insertion sort
```

## Interface ##
```
void sort(std::vector<int> &);
const char *self();
```
The first implement algs while the second show its info.