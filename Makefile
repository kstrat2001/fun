# Makefile for memmgr projectr

#SOURCE=bld/main.cpp bld/heap.cpp include/heap.h

INCLUDE_DIR=include
SOURCE_DIR=bld
OUTPUT_DIR=bin
OBJECT_DIR=obj
BINARY_NAME=fun

BINARY=$(OUTPUT_DIR)/$(BINARY_NAME)
SOURCE=$(wildcard $(SOURCE_DIR)/*.cpp)
INCLUDES=$(wildcard $(INCLUDE_DIR)/*.h)
OBJS=$(patsubst $(SOURCE_DIR)/%.cpp, $(OBJECT_DIR)/%.o, $(SOURCE))

CXX=g++
CXXFLAGS=-Wall -g -c
LD_FLAGS=

all: $(BINARY)

$(BINARY): $(OBJS)
	$(CXX) $(LD_FLAGS) -o $@ $^

obj/%.o: bld/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -o $@ $^

clean:
	rm -rf $(OUTPUT_DIR)/*
	rm -rf $(OBJECT_DIR)/*
