SRC_DIR := src
INCLUDE_DIR := include
LIB_DIR := ../lib

HEADER := $(wildcard $(INCLUDE_DIR)/*.hpp)
SRC := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*.cc)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
SO := $(patsubst %.o, %.so, $(OBJ))

CC := g++
CXXFLAG := -Wall -Wextra -O2 -c -fPIC -Iinclude -std=c++11

all: $(SO)
	if [ ! -d "../lib" ]; then mkdir ../lib; fi
	for so in $(SO); do mv $$so $(LIB_DIR); done
	rm $(OBJ)

$(SO): %.so: %.o
	$(CC) $< -o $@ -shared

$(OBJ): %.o: %.cpp $(HEADER)
	$(CC) $< -o $@ $(CXXFLAG)

clean:
	rm -f $(OBJ)

rebuild: clean all

.PHONY: all clean rebuild
