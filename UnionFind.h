#include<stdio.h>

#ifndef UNIONFIND_H
#define UNIONFIND_H

struct UnionFind {
    UnionFind* p;
    int rank;
    int vertex;

    UnionFind(int index);
    UnionFind* find();
    UnionFind* link(UnionFind* u);
    UnionFind* take_union(UnionFind* u);
};

#endif