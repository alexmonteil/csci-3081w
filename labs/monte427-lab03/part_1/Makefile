# The CXXFLAGS variable sets compile flags for g++:
#  -g          compile with debug information
#  -std=c++11  use the c++ standard language definition

CXX=g++
CXXFLAGS = -std=c++11 -g

.DEFAULT_GOAL := all
.PHONY: all clean

all: memory_app

memory_app: memory.o lab_types.o
	$(CXX) $(CXXFLAGS) memory.o lab_types.o -o memory_app

memory.o: memory.cc
	$(CXX) $(CXXFLAGS) -c memory.cc -o memory.o

lab_types.o: lab_types.cc lab_types.h
	$(CXX) $(CXXFLAGS) -c lab_types.cc -o lab_types.o

clean:
	rm -f *.o memory_app