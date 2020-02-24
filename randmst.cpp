#include <stdio.h>
#include "Graph.h"
#include "UnionFind.h"

int main(int argc, char* argv[]) {
    Graph* g = new Graph(1000,2);
    g->generate_MST_prims();
    
    printf("Weight is: %f\n", g->mstweight);
}