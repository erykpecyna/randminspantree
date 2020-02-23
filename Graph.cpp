#include "Graph.h"

Graph::Graph(int n, int d) {
    this->n = n;
    this->edges.reserve(n);
    this->mst.reserve(n-1);
}

Graph::~Graph() {

}