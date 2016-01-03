SRC := $(wildcard *.cpp) 
OBJ := $(patsubst %.cpp, %.o, $(SRC))
SO := $(patsubst %.cpp, %.so, $(SRC))
HEAD := $(wildcard *.hpp)
POSITION := /usr/lib

CC := g++
CFLAG := -shared -fPIC
OBJFLAG := -Wall -c

all: $(SO)
	for so in $(SO); do sudo cp $$so $(POSITION); done

$(SO): %.so: %.o
	$(CC) $< -o $@ $(CFLAG)

$(OBJ): %.o: %.cpp $(HEAD)
	$(CC) $< -o $@ $(OBJFLAG)

clean:
	rm $(OBJ)
	rm $(SO)
	for so in $(SO); do sudo rm $(POSITION)/$$so -f; done

rebuild: clean all

.PHONY: all clean rebuild
