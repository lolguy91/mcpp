UNAME_S = $(shell uname -s)

CC = clang++
CFLAGS = -O2 -g
CFLAGS += -Ilib/glad/include -Ilib/glfw/include -Ilib/ConcurrentQueue -Isrc -Ivendor/ -I.
LDFLAGS = lib/glad/src/glad.o lib/glfw/src/libglfw3.a -ldl -lpthread -lGL



SRC  = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp) $(wildcard src/**/**/**/**/*.cpp) $(wildcard src/**/**/**/**/**/*.cpp) $(wildcard src/**/**/**/**/**/**/*.cpp)
OBJ  = $(SRC:.cpp=.o)
BIN  = ./bin


.PHONY: all clean

all: dirs libs game

libs:
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c
	cd lib/glfw && cmake . && make

dirs:
	mkdir -p ./$(BIN)

run: game
	$(BIN)/game

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)

getassets:
	python tools/getassets.py