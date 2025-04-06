// Email: doodluz7@gmail.com

#pragma once
class Queue {
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    void enqueue(int val);
    int dequeue();
    bool isEmpty() const;
};