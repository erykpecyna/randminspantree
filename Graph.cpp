#include "Graph.h"

using namespace std;

Graph::Graph(int n, int d) {
    this->n = n;
    this->d = d;
    sets.reserve(n);
    mstedges = 0;

    if (d == 0) {
        lim = (10./n) + 0.01;
    } else {
        lim = ((pow(d, 2) * 10) / n) + pow(d,2) * 0.01 + (d-1) * 0.01 ;
    }
}

Graph::~Graph() {
    for(UnionFind* set: sets) {
        delete set;
    }
    mstweight = 0;
}

void Graph::generate_vertices() {
    vector_coordinates.reserve(n);
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
            if(d==0) {
                float rand = unif(generator);
                if (lim > rand)
                    edges.push_back(edge_t(rand, edge(i, j)));
            } else {
                float dist = euclid_distance(vector_coordinates[i], vector_coordinates[j]);
                if (lim > dist)
                    edges.push_back(edge_t(dist, edge(i,j)));
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
    if (d!=0)
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
            mstedges++;
            mstweight += weight;
            sets[u]->find()->take_union(sets[v]->find());
        }
        if (mstedges >= n-1)
            return;
    }

    printf("Bah humbug, the bound is too tight\n");
}