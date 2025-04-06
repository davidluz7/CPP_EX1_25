// Email: doodluz7@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.hpp"
#include "algorithms.hpp"

using namespace graph;

TEST_CASE("בדיקה בסיסית של addEdge והדפסה") {
    Graph g(4);
    CHECK_NOTHROW(g.addEdge(0, 1));
    CHECK_NOTHROW(g.addEdge(1, 2, 3));
    CHECK_NOTHROW(g.print_graph());
}

TEST_CASE("בדיקת removeEdge") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    CHECK_NOTHROW(g.removeEdge(1, 2));
    CHECK_THROWS(g.removeEdge(1, 2)); // ניסיון למחוק שוב אמור לזרוק
}

TEST_CASE("בדיקת BFS מחזיר עץ") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK_NOTHROW(bfsTree.print_graph());
}

TEST_CASE("בדיקת DFS מחזיר עץ") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK_NOTHROW(dfsTree.print_graph());
}

TEST_CASE("בדיקת Dijkstra") {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);

    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    CHECK_NOTHROW(dijkstraTree.print_graph());
}

TEST_CASE("בדיקת Kruskal ו-Prim") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    Graph kruskalTree = Algorithms::kruskal(g);
    Graph primTree = Algorithms::prim(g);

    CHECK_NOTHROW(kruskalTree.print_graph());
    CHECK_NOTHROW(primTree.print_graph());
}
