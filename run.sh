#!/bin/bash
LD_LIBRARY_PATH=lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
g++ SortCompare.cpp -ldl -Wall -Wextra -O2 -g -o SortCompare.out
./SortCompare.out\
		-linsertion\
		-lqsort\
		-lheap\
		-lbubble\
		-lradix\
		-lqsort3way\
		-lmerge\
		-lshell\
		-lselection
