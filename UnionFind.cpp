#include "UnionFind.h"

UnionFind::UnionFind() {
    this->rank = 0;
    this->p = this;
}

UnionFind* UnionFind::find() {
    if (this->p == this) return this;

    this->p = this->p->find();
    return this->p;
}

UnionFind* UnionFind::link(UnionFind* u) {
    if (this->rank > u->rank) {
        u->p = this;
        return this;
    } else if (u->rank > this->rank) {
        this->p = u;
        return u;
    }
    
    this->rank++;
    u->p = this;
    return this;
}

UnionFind* UnionFind::take_union(UnionFind* u) {
    return this->link(u);
}