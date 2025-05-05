#include "heap.h"
#include "functional"
#include "pair.h"

template <typename T, typename compare_function, typename get_function>
priority_queue<T, compare_function, get_function>::priority_queue(get_function get, compare_function compare)
    : get(get), compare(compare) {}

template <typename T, typename compare_function, typename get_function>
void priority_queue<T, compare_function, get_function>::insert(T value) {
    if (count >= INITIAL_CAPACITY) return; // Prevent overflow
    heap[count] = value;
    heapifyUp(count);
    count++;
}

template <typename T, typename compare_function, typename get_function>
void priority_queue<T, compare_function, get_function>::pop() {
    if (count == 0) return;
    std::swap(heap[0], heap[count - 1]);
    count--;
    heapifyDown(0);
}

template <typename T, typename compare_function, typename get_function>
T priority_queue<T, compare_function, get_function>::top() {
    return heap[0];
}

template <typename T, typename compare_function, typename get_function>
bool priority_queue<T, compare_function, get_function>::empty() const {
    return count == 0;
}

template <typename T, typename compare_function, typename get_function>
int priority_queue<T, compare_function, get_function>::size() const {
    return count;
}

template <typename T, typename compare_function, typename get_function>
void priority_queue<T, compare_function, get_function>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (compare(get(heap[index]), get(heap[parent]))) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T, typename compare_function, typename get_function>
void priority_queue<T, compare_function, get_function>::heapifyDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < count && compare(get(heap[left]), get(heap[best]))) {
            best = left;
        }
        if (right < count && compare(get(heap[right]), get(heap[best]))) {
            best = right;
        }
        if (best != index) {
            std::swap(heap[index], heap[best]);
            index = best;
        } else {
            break;
        }
    }
}

// Explicit template instantiations for specific types
template class priority_queue<int, std::function<bool(int, int)>, std::function<int(int)>>;
template class priority_queue<pair<int, int>,std::function<bool(int, int)>, std::function<int(pair<int, int>)>>;
template class priority_queue<pair<pair<int,int>, int>,std::function<bool(int, int)>, std::function<int(pair<pair<int,int>, int>)>>;