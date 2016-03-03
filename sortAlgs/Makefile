SRC := $(wildcard *.cpp) 
OBJ := $(patsubst %.cpp, %.o, $(SRC))
SO := $(patsubst %.cpp, %.so, $(SRC))
HEAD := $(wildcard *.hpp)
POSITION := ../lib

CC := g++
CFLAG := -shared
OBJFLAG := -Wall -Wextra -O2 -c -fPIC

all: $(SO)
	mkdir ../lib
	for so in $(SO); do mv $$so $(POSITION); done

$(SO): %.so: %.o
	$(CC) $< -o $@ $(CFLAG)

$(OBJ): %.o: %.cpp $(HEAD)
	$(CC) $< -o $@ $(OBJFLAG)

clean:
	rm -f $(OBJ)

rebuild: clean all

.PHONY: all clean rebuild
