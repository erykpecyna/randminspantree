#include<stdio.h>
#include<vector>
#include<random>
#include<chrono>
#include<tuple>
#include<algorithm>
#include "helpers.h"
#include "UnionFind.h"

#ifndef GRAPH_H
#define GRAPH_H

typedef std::tuple<int, int> edge;
typedef std::tuple<double, edge> edge_t;

struct Graph {
    int n;
    int d;
    std::vector<edge_t> edges;
    std::vector<UnionFind*> sets;
    double mstweight;
    int mstedges;
    std::vector<std::tuple<double,double,double,double>> vector_coordinates;
    bool *in_set;

    Graph(int n, int d);
    ~Graph();

    // Only necessary for dimension > 1
    void generate_vertices();

    void generate_edges();

    void generate_set();
    
    void generate_MST_kruskal();
};

#endif