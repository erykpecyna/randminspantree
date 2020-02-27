CXX = g++
CXXFLAGS = -Wall -g -O0

all: randmst

randmst: randmst.o Graph.o UnionFind.o helpers.o
	$(CXX) $(CXXFLAGS) -o randmst randmst.o Graph.o UnionFind.o helpers.o

randmst.o: randmst.cpp Graph.h
	$(CXX) $(CXXFLAGS) -c randmst.cpp

graph.o: Graph.h
	$(CXX) $(CXXFLAGS) -c Graph.cpp

unionfind.o: UnionFind.h
	$(CXX) $(CXXFLAGS) -c UnionFind.cpp

helpers.o: helpers.h
	$(CXX) $(CXXFLAGS) -c helpers.cpp

clean:
	rm randmst *.o