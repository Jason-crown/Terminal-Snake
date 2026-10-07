CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
TARGET = snake
OBJ = snake.o
EXE = test.exe

ifeq ($(OS), Windows_NT)
    DELETE = del
else
    DELETE = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

%.o: snake.h
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(DELETE) $(OBJ) $(TARGET)

ifeq ($(OS), Windows_NT)
	$(DELETE) $(EXE)
endif

fix:
	make clean
	make run

.PHONY: all clean fix run

run: $(TARGET)
	./$(TARGET)