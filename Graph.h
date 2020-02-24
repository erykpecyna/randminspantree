#include<stdio.h>
#include<vector>
#include<random>
#include<tuple>
#include "helpers.h"

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    int n;
    int d;
    std::vector<std::vector<double>> edges;
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