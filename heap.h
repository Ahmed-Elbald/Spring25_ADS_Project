#ifndef HEAP_H
#define HEAP_H

#include "pair.cpp"

// Min heap specialized for pair<int, int>
class min_heap {
    const int INITIAL_CAPACITY = 100000;
    custom::pair<int, int> heap[100000];
    int count = 0;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    min_heap();
    ~min_heap() = default;

    void push(custom::pair<int, int> value);
    void pop();
    custom::pair<int, int> top();
    bool empty() const;
    int size() const;
};

#endif // HEAP_H