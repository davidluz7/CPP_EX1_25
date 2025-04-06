// Email: doodluz7@gmail.com

#pragma once
struct PQNode {
    int vertex;
    int priority;
};

class PriorityQueue {
    PQNode* array;
    int size;
    int capacity;

public:
    PriorityQueue(int cap);
    ~PriorityQueue();
    void push(int vertex, int priority);
    PQNode pop();
    bool isEmpty() const;
    int getMinIndex() const;
};