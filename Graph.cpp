#include "Graph.h"

using namespace std;

Graph::Graph(int n, int d) {
    this->n = n;
    this->d = d;
    edges.reserve(n);
    vector_coordinates.reserve(n);
    sets.reserve(n);
    mstedges = 0;
}

Graph::~Graph() {

}

void Graph::generate_vertices() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    uniform_real_distribution<float> unif(0,1);

    for (int i = 0; i < n; i++) {
        float coord[4] = {0.,0.,0.,0.};
        for (int j = 0; j < d; j++) {
            coord[j] = unif(generator);
        }
        this->vector_coordinates.push_back(tuple<float, float, float, float>(coord[0], coord[1], coord[2], coord[3]));
    }    
}

void Graph::generate_edges() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    uniform_real_distribution<float> unif(0,1);

    for(int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {
            if(d==1) {
                edges.push_back(edge_t(unif(generator), edge(i, j)));
            } else {
                edges.push_back(edge_t(euclid_distance(vector_coordinates[i], vector_coordinates[j]), edge(i,j)));
            }
        }
    }

    vector_coordinates.clear();

    
    
    sort(edges.begin(), edges.end());
}

void Graph::generate_set() {
    for (int i = 0; i < n; i++) {
        UnionFind* set = new UnionFind();
        sets.push_back(set);
    }
}

void Graph::generate_MST_kruskal() {
    generate_vertices();
    generate_edges();
    generate_set();
    
    for(edge_t e: edges) {
        int u,v;
        edge ed;
        float weight;
        tie(weight, ed) = e;
        tie(u,v) = ed;
        
        if(sets[u]->find() != sets[v]->find()) {
            mstweight += weight;
            sets[u]->find()->take_union(sets[v]->find());
        }
    }

}