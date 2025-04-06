// Email: doodluz7@gmail.com
#pragma once
class UnionFind {
    int* parent;
    int* rank;
    int size;

public:
    UnionFind(int n);
    ~UnionFind();
    int find(int x);
    void unite(int x, int y);
};