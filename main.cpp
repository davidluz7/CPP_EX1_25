// Email: doodluz7@gmail.com

#include "graph.hpp"
#include "algorithms.hpp"
#include <iostream>

int main() {
    graph::Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.print_graph();

    auto bfs_tree = graph::Algorithms::bfs(g, 0);
    std::cout << "\nBFS Tree:" << std::endl;
    bfs_tree.print_graph();

    return 0;
}