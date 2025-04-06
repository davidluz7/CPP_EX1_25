// Email: doodluz7@gmail.com

#pragma once
#include <iostream>
namespace graph {

    struct Edge {
        int dest;
        int weight;
        Edge* next;
        Edge(int d, int w) : dest(d), weight(w), next(nullptr) {}
    };

    class Graph {
        int vertices;
        Edge** adjacencyList;

    public:
        Graph(int v);
        ~Graph();
        void addEdge(int src, int dest, int weight=1);
        void removeEdge(int src, int dest);
        void print_graph() const;
        int getVertices() const { return vertices; } 
        Edge** getAdjacencyList() const { return adjacencyList; }
    };

}
