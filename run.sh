#!/bin/bash
g++ SortCompare.cpp -ldl -g -o SortCompare.out
./SortCompare.out insertion.so qsort.so heap.so bubble.so radix.so qsort3way.so
