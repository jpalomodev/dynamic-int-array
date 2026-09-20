SHELL = /usr/bin/bash
.PHONY: clean

CC = g++
CCFLAGS = -Wall -Wextra -Werror -pedantic -g -std=c++20

main: main.o
	$(CC) $(CCFLAGS) -o main main.o

clean: rm -f main *.o
