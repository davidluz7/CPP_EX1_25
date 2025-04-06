// Email: doodluz7@gmail.com

#pragma once
#include "graph.hpp"
#include "queue.hpp"
#include "priority_queue.hpp"
#include "union_find.hpp"
namespace graph {

    class Algorithms {
    public:
        static Graph bfs(const Graph& g, int start);
        static Graph dfs(const Graph& g, int start);
        static Graph dijkstra(const Graph& g, int start);
        static Graph prim(const Graph& g);
        static Graph kruskal(const Graph& g);
    };

}