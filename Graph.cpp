#include "Graph.h"
#include <random>
#include <chrono>

using namespace std;

Graph::Graph(int n, int d) {
    n = n;
    edges.reserve(n);
    vector_coordinates.reserve(n);
    in_set = new bool[n]();
    mstedges = 0;
}

Graph::~Graph() {
    delete in_set;
}

void Graph::generate_vertices() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    for (int i = 0; i < n; i++) {
        double coord[4] = {0.,0.,0.,0.};
        for (int j = 0; j < d; j++) {
            coord[j] = generator();
        }
        this->vector_coordinates.push_back(tuple<double, double, double, double>(coord[0], coord[1], coord[2], coord[3]));
    }    
}

void Graph::generate_edges() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    for(int row = 0; row < n; row++) {
        vector<double> row_vec;
        for (int col = 0; col < n-row; col++) {
            if(d==1) {
                row_vec.push_back(generator());
            } else {
                row_vec.push_back(euclid_distance(vector_coordinates[row], vector_coordinates[row+col]));
            }
        }
        edges.push_back(row_vec);
    }
}

void Graph::generate_MST_prims() {
    generate_vertices();
    generate_edges();
    
    // Add first vertex and first edge
    in_set[0] = true;
    int min;
    vector<double> first_row;
    for (int i = 0; i < n; i++) {
        if(first_row[i] < first_row[min])
            min = i;
    }
    mstweight += first_row[min];
    mstedges += 1;

    // Main part of Prims
    while (mstedges < n-1) {
        
    }

}