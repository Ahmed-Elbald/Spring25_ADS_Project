#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

// TODO -> use vectors instead of arrays
template <typename T, typename compare_function, typename get_function>
class Heap {
    const int INITIAL_CAPACITY = 100000;
    T arr[100000];
    int count = 0;

    get_function get;
    compare_function compare;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    Heap(get_function get, compare_function compare) : get(get), compare(compare) {}
    ~Heap() = default;
    void insert(T value);
    void pop();
    T top();
    bool empty() const;
    int size() const;
};

#endif // HEAP_H
