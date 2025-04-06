// Email: doodluz7@gmail.com

#include "graph.hpp"
#include <stdexcept>

namespace graph{

    Graph::Graph(int v) : vertices(v) {
        adjacencyList = new Edge*[v];
        for (int i = 0; i < v; i++)
            adjacencyList[i] = nullptr;
    }

    Graph::~Graph() {
        for (int i = 0; i < vertices; i++) {
            Edge* current = adjacencyList[i];
            while (current != nullptr) {
                Edge* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] adjacencyList;
    }

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            throw std::out_of_range("Invalid edge indices");
        }

        Edge* newEdge = new Edge(dest, weight);
        newEdge->next = adjacencyList[src];
        adjacencyList[src] = newEdge;

        // הוספת צלע הפוכה (לא מכוון)
        Edge* newEdgeBack = new Edge(src, weight);
        newEdgeBack->next = adjacencyList[dest];
        adjacencyList[dest] = newEdgeBack;
    }

    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            throw std::out_of_range("Invalid edge indices");
        }

        // הסרה מה-src ל-dest
        Edge* current = adjacencyList[src];
        Edge* prev = nullptr;
        bool found = false;
        while (current != nullptr) {
            if (current->dest == dest) {
                found = true;
                if (prev == nullptr) {
                    adjacencyList[src] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
        if (!found) {
            throw std::runtime_error("Edge not found");
        }

        // הסרה מה-dest ל-src (צלע הפוכה)
        current = adjacencyList[dest];
        prev = nullptr;
        while (current != nullptr) {
            if (current->dest == src) {
                if (prev == nullptr) {
                    adjacencyList[dest] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    void Graph::print_graph() const {
        for (int i = 0; i < vertices; i++) {
            std::cout << i << ": ";
            Edge* current = adjacencyList[i];
            while (current != nullptr) {
                std::cout << current->dest << " -> ";
                current = current->next;
            }
            std::cout << "NULL" << std::endl;
        }
    }
};