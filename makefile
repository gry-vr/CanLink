# Makefile for CanLink

# Compiler settings
CXX      := g++
CC       := gcc
CXXFLAGS := -Wall -Wextra -std=c++17
CFLAGS   := -Wall -Wextra -std=c11
INCLUDES := -Iinclude

# Sources and final program name
PROGRAM  := canlink
SRCS_CPP := src/decoding.cpp src/main.cpp src/util.cpp # If you have more .cpp files, add them here
SRCS_C   := src/dura_max.c     # If you have more .c files, add them here

# Derive object names from the sources
OBJS_CPP := $(SRCS_CPP:.cpp=.o)
OBJS_C   := $(SRCS_C:.c=.o)

.PHONY: all clean debug

# Default target: build the executable
all: $(PROGRAM)

# Link all objects into the final executable
$(PROGRAM): $(OBJS_CPP) $(OBJS_C)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Compile rules for .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compile rules for .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Debug build: add sanitizers, debug symbols, no optimization
debug: CXXFLAGS += -fsanitize=address -fsanitize=undefined -g -O0
debug: CFLAGS   += -fsanitize=address -fsanitize=undefined -g -O0
debug: clean all

# Clean up build artifacts
clean:
	rm -f $(OBJS_CPP) $(OBJS_C) $(PROGRAM)

