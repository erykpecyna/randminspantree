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
typedef std::tuple<float, edge> edge_t;

struct Graph {
    int n;
    int d;
    float lim;
    std::vector<edge_t> edges;
    std::vector<UnionFind*> sets;
    float mstweight;
    int mstedges;
    std::vector<std::tuple<float,float,float,float>> vector_coordinates;

    Graph(int n, int d);
    ~Graph();

    // Only necessary for dimension > 1
    void generate_vertices();

    void generate_edges();

    void generate_set();
    
    void generate_MST_kruskal();
};

#endif