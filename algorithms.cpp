// Email: doodluz7@gmail.com

#include "algorithms.hpp"
#include <stdexcept>
#include <functional>
#include <climits>

namespace graph {

    Graph Algorithms::bfs(const Graph& g, int start) {
        Graph tree(g.getVertices());
        Queue q;
        bool* visited = new bool[g.getVertices()];
        for (int i = 0; i < g.getVertices(); i++) visited[i] = false;

        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int current = q.dequeue();
            Edge* edge = g.getAdjacencyList()[current];
            while (edge != nullptr) {
                if (!visited[edge->dest]) {
                    visited[edge->dest] = true;
                    tree.addEdge(current, edge->dest, edge->weight);
                    q.enqueue(edge->dest);
                }
                edge = edge->next;
            }
        }

        delete[] visited;
        return tree;
    }

    Graph Algorithms::dfs(const Graph& g, int start) {
        Graph tree(g.getVertices());
        bool* visited = new bool[g.getVertices()];
        for (int i = 0; i < g.getVertices(); i++) visited[i] = false;

        // פונקציה עזר רקורסיבית פנימית
        std::function<void(int)> dfsVisit = [&](int v) {
            visited[v] = true;
            Edge* edge = g.getAdjacencyList()[v];
            while (edge != nullptr) {
                if (!visited[edge->dest]) {
                    tree.addEdge(v, edge->dest, edge->weight);
                    dfsVisit(edge->dest);
                }
                edge = edge->next;
            }
        };

        dfsVisit(start);
        delete[] visited;
        return tree;
    }

    Graph Algorithms::dijkstra(const Graph& g, int start) {
        Graph tree(g.getVertices());
        int* dist = new int[g.getVertices()];
        int* parent = new int[g.getVertices()];

        for (int i = 0; i < g.getVertices(); i++) {
            dist[i] = INT_MAX;
            parent[i] = -1;
        }
        dist[start] = 0;

        PriorityQueue pq(g.getVertices());
        pq.push(start, 0);

        while (!pq.isEmpty()) {
            auto current = pq.pop();
            int u = current.vertex;
            Edge* edge = g.getAdjacencyList()[u];
            while (edge != nullptr) {
                int v = edge->dest;
                int w = edge->weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push(v, dist[v]);
                }
                edge = edge->next;
            }
        }

        for (int i = 0; i < g.getVertices(); i++) {
            if (parent[i] != -1) {
                tree.addEdge(i, parent[i], dist[i] - dist[parent[i]]);
            }
        }

        delete[] dist;
        delete[] parent;
        return tree;
    }

    Graph Algorithms::prim(const Graph& g) {
        Graph tree(g.getVertices());
        bool* inTree = new bool[g.getVertices()];
        int* key = new int[g.getVertices()];
        int* parent = new int[g.getVertices()];

        for (int i = 0; i < g.getVertices(); i++) {
            key[i] = INT_MAX;
            inTree[i] = false;
            parent[i] = -1;
        }

        key[0] = 0;
        PriorityQueue pq(g.getVertices());
        pq.push(0, 0);

        while (!pq.isEmpty()) {
            auto current = pq.pop();
            int u = current.vertex;
            inTree[u] = true;
            Edge* edge = g.getAdjacencyList()[u];
            while (edge != nullptr) {
                int v = edge->dest;
                int w = edge->weight;
                if (!inTree[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push(v, key[v]);
                }
                edge = edge->next;
            }
        }

        for (int i = 1; i < g.getVertices(); i++) {
            if (parent[i] != -1) {
                tree.addEdge(i, parent[i], key[i]);
            }
        }

        delete[] inTree;
        delete[] key;
        delete[] parent;
        return tree;
    }

    Graph Algorithms::kruskal(const Graph& g) {
        Graph tree(g.getVertices());
        UnionFind uf(g.getVertices());

        // נעבור על כל הצלעות ונשמור במערך
        struct TempEdge { int src, dest, weight; };
        TempEdge* edges = new TempEdge[1000]; // הנחה שיש עד 1000 צלעות
        int edgeCount = 0;

        for (int i = 0; i < g.getVertices(); i++) {
            Edge* e = g.getAdjacencyList()[i];
            while (e != nullptr) {
                if (i < e->dest) { // כדי לא להכפיל צלעות
                    edges[edgeCount++] = {i, e->dest, e->weight};
                }
                e = e->next;
            }
        }

        // מיון בועות פשוט (כי אסור להשתמש ב-STL)
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j+1].weight) {
                    auto tmp = edges[j];
                    edges[j] = edges[j+1];
                    edges[j+1] = tmp;
                }
            }
        }

        for (int i = 0; i < edgeCount; i++) {
            if (uf.find(edges[i].src) != uf.find(edges[i].dest)) {
                uf.unite(edges[i].src, edges[i].dest);
                tree.addEdge(edges[i].src, edges[i].dest, edges[i].weight);
            }
        }

        delete[] edges;
        return tree;
    }

};
