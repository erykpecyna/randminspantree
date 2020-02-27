#include <stdio.h>
#include "Graph.h"
#include "UnionFind.h"

int main(int argc, char* argv[]) {
    int n = std::stoi(argv[2]);
    int num_trials = std::stoi(argv[3]);
    int d = std::stoi(argv[4]);

    float totalweight = 0;

    for (int i = 0; i < num_trials; i++) {
        Graph* g = new Graph(n,d);
        g->generate_MST_kruskal();
        totalweight += g->mstweight;
        delete g;
    }

    printf("%f %d %d %d\n", totalweight / num_trials, n, num_trials, d);
}