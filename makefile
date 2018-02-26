# Makefile to compile
# Variables with the options for compilation
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List of the objects to compile
OBJECTS = state.o ndfa.o main.o
DEPS = state.hpp ndfa.hpp main.cpp
# Variables with rule names
NDFA = ndfa

# Default rule
all: $(NDFA)

# Rule to compile object files
# Commented because it is the same as an explicit rule in Make
#   https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html
#%.o: %.c
	#$(CXX) -c -o $@ $< $(CXXFLAGS)

# Rule to compile the program
$(NDFA): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	-rm -f *.o

.PHONY: all clean
