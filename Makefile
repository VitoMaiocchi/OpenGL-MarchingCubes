CXX = g++
CC = gcc

LIBS=-L. libraries/lib/libglfw.so.3.3 -lGL
FLAGS=$(CFLAGS) -g -O0 -Ilibraries/include

GREEN=\033[1;32m
RED=\033[1;31m
BLUE=\033[1;34m
YELLOW=\033[1;33m
END=\033[0m

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard src/*.hpp)

src/glad.o: src/glad.c
	@echo -e "$(YELLOW)Compiling $<...$(END)"
	$(CXX) $(FLAGS) -c $< -o $@

%.o: %.cpp $(HEADERS)
	@echo -e "$(YELLOW)Compiling $<...$(END)"
	$(CXX) $(FLAGS) -c $< -o $@

MarchingCubes: $(OBJS) src/glad.o
	@echo -e "$(GREEN)Linking Final Executable...$(END)"
	$(CXX) -o MarchingCubes $^ -L. libraries/lib/libglfw.so.3.3 -lGL

clean:
	rm -f MarchingCubes src/*.o

.DEFAULT_GOAL=MarchingCubes
.PHONY: clean
