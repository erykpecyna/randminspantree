#include <stdio.h>
#include "Graph.h"
#include "UnionFind.h"

int main(int argc, char* argv[]) {
    // n = 128; 256; 512; 1024; 2048; 4096; 8192; 16384; 32768; 65536; 131072; 262144;
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