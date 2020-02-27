#include<stdio.h>

#ifndef UNIONFIND_H
#define UNIONFIND_H

struct UnionFind {
    UnionFind* p;
    int rank;

    UnionFind();
    UnionFind* find();
    UnionFind* link(UnionFind* u);
    UnionFind* take_union(UnionFind* u);
};

#endif