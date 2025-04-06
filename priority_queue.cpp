// Email: doodluz7@gmail.com

#include "priority_queue.hpp"

PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    size = 0;
    array = new PQNode[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] array;
}


void PriorityQueue::push(int vertex, int priority) {
    if (size == capacity) {
        // לא מרחיבים דינמית כי זה לא נדרש במטלה
        return;
    }
    array[size].vertex = vertex;
    array[size].priority = priority;
    size++;
}

PQNode PriorityQueue::pop() {
    if (isEmpty()) {
        return {-1, -1}; // ערך לא חוקי לציין שהרשימה ריקה
    }
    int minIdx = getMinIndex();
    PQNode result = array[minIdx];
    array[minIdx] = array[size - 1]; // מחליף עם האחרון
    size--;
    return result;
}

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

int PriorityQueue::getMinIndex() const {
    int minIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i].priority < array[minIdx].priority) {
            minIdx = i;
        }
    }
    return minIdx;
}
