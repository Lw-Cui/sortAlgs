CC 	= g++-4.9 -std=c++14
CXXFLAG	= -O0 -Wall -Wextra -W -ggdb3

SortCompare.out: SortCompare.o
	$(CC) $^ -o $@ $(CXXFLAG) -ldl

SortCompare.o: SortCompare.cpp
	$(CC) $< -c $(CXXFLAG)
	
clean:
	rm -f *.o SortCompare.out

rebuild:	clean SortCompare.out

.PHONY:	clean rebuild