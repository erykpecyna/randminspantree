CXX = g++
CXXFLAGS = -Wall -g

all: randmst

randmst: randmst.o Graph.o UnionFind.o
	$(CXX) $(CXXFLAGS) -o randmst randmst.o Graph.o UnionFind.o

randmst.o: randmst.cpp Graph.h
	$(CXX) $(CXXFLAGS) -c randmst.cpp

graph.o: Graph.h
	$(CXX) $(CXXFLAGS) -c Graph.cpp

unionfind.o: UnionFind.h
	$(CXX) $(CXXFLAGS) -c UnionFind.cpp

clean:
	rm randmst *.o