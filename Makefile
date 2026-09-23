SHELL = /usr/bin/bash
.PHONY: clean

CC = g++
CCFLAGS = -Wall -Wextra -Werror -Wconversion -Wshadow -pedantic -g -fsanitize=address,undefined -std=c++20

TARGET = DynamicIntArray

SOURCES = main.cpp DynamicIntArray.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
