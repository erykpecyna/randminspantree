#include<stdio.h>
#include<vector>
#include<random>
#include<tuple>

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    int n;
    int d;
    std::vector<std::vector<double>> edges;
    std::vector<std::tuple<int, int>> mst;
    std::vector<std::tuple<int,int,int,int>> vector_coordinates;

    Graph(int n, int d);
    ~Graph();    
    
    void generate_MST_prims();
};

#endif