#!/bin/bash
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
