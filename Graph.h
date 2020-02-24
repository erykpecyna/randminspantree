#include<stdio.h>
#include<vector>
#include<random>
#include<tuple>
#include "helpers.h"

#ifndef GRAPH_H
#define GRAPH_H

typedef std::tuple<int, int> edge;
typedef std::tuple<double, edge> edge_t;

class Graph {
    int n;
    int d;
    std::vector<edge_t> edges;
    double mstweight;
    int mstedges;
    std::vector<std::tuple<double,double,double,double>> vector_coordinates;
    bool *in_set;

    Graph(int n, int d);
    ~Graph();

    // Only necessary for dimension > 1
    void generate_vertices();

    void generate_edges();
    
    void generate_MST_prims();
};

#endif