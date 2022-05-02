CC = c++

CXXFLAGS = -Wall -std=c++17 -Iinclude/
LDFLAGS = 

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
PROGRAM = out
BIN = bin

.PHONY: all clean

all: clean dirs libs $(PROGRAM)

run: clean all
	./$(BIN)/$(PROGRAM)

dirs:
	mkdir -p ./$(BIN)

libs:

$(PROGRAM): $(OBJ)
	$(CC) -o $(BIN)/$(PROGRAM) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS) 

clean:
	rm -rf $(BIN) $(OBJ)