# Makefile to compile
# Variables with the options for compilation
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List of the objects to compile
OBJECTS = Viewer.o main.o
DEPS = Edge.hpp Graph.hpp InfoNode.hpp Node.hpp Vertex.hpp Viewer.hpp
# Variables with rule names
VIEWER = graph

# Default rule
all: $(VIEWER)

# Rule to compile object files
# Commented because it is the same as an explicit rule in Make
#   https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html
#%.o: %.c
	#$(CXX) -c -o $@ $< $(CXXFLAGS)

# Rule to compile the program
$(VIEWER): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o

.PHONY: all clean
