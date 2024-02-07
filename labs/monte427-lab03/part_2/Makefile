CXX=g++
CXXFLAGS = -std=c++14 -g

SOURCES = $(wildcard *.cc)
OBJFILES = $(notdir $(SOURCES:.cc=.o))

.DEFAULT_GOAL := all
.PHONY: all clean
all: entity_app

# Applicaiton Targets:
entity_app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $@

# Object File Targets:
%.o:  %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *_app *.exe

