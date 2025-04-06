// Email: doodluz7@gmail.com

#include "queue.hpp"
#include <stdexcept>

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    Node* temp = front;
    int value = temp->value;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return value;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}
