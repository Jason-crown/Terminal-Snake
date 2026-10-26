CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
TARGET = Snake
OBJ = main.o board.o initialize.o logic.o movement.o print.o
EXE = Snake.exe

ifeq ($(OS), Windows_NT)
    DELETE = del
else
    DELETE = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c snake.h
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