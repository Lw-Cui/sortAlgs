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
g++ libbubble.cpp -o libbubble.o -Wall -c
g++ libbubble.o -o libbubble.so -shared -fPIC
g++ libheap.cpp -o libheap.o -Wall -c
g++ libheap.o -o libheap.so -shared -fPIC
g++ libinsertion.cpp -o libinsertion.o -Wall -c
g++ libinsertion.o -o libinsertion.so -shared -fPIC
g++ libmerge.cpp -o libmerge.o -Wall -c
g++ libmerge.o -o libmerge.so -shared -fPIC
...

for so in  libbubble.so  libheap.so  libinsertion.so  libmerge.so  libqsort3way.so  libqsort.so  libradix.so  libshell.so; do sudo cp $so /usr/lib; done

```
*Yeah you should be granted `sudo` privilege.*


* Then in the root directory of this repo you could type(or just run the `run.sh` directly):
```
g++ SortCompare.cpp -ldl -g -o SortCompare.out
./SortCompare.out \
		-linsertion \
		-lqsort\
		-lheap\
		-lbubble\
		-lradix\
		-lqsort3way\
		-lmerge\
		-lshell

``` 
Here you could replace those *.so with library you choose.

 * Result
```
For 10000 integers
    Quick sort is 1.27 times faster than Qsort(3 way)
    Qsort(3 way) is 1.04 times faster than Merge sort
    Merge sort is 1.00 times faster than Radix sort
    Radix sort is 1.02 times faster than Shell sort
    Shell sort is 1.18 times faster than Heap sort
    Heap sort is 57.43 times faster than Insertion sort
    Insertion sort is 3.75 times faster than Bubble sort

For 30000 integers
    Radix sort is 1.01 times faster than Quick sort
    Quick sort is 1.11 times faster than Qsort(3 way)
    Qsort(3 way) is 1.11 times faster than Merge sort
    Merge sort is 1.11 times faster than Shell sort
    Shell sort is 1.10 times faster than Heap sort
    Heap sort is 148.07 times faster than Insertion sort
    Insertion sort is 3.89 times faster than Bubble sort
	....
```
