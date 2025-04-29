#ifndef HEAP_H
#define HEAP_H


// Template declaration for priority_queue
template <typename T, typename compare_function, typename get_function>
class priority_queue {
    const int INITIAL_CAPACITY = 100000;
    T heap[100000];
    int count = 0;

    get_function get;
    compare_function compare;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    priority_queue(get_function get, compare_function compare);
    ~priority_queue() = default;

    void insert(T value);
    void pop();
    T top();
    bool empty() const;
    int size() const;
};

#endif // HEAP_H