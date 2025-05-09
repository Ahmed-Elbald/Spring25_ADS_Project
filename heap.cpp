#include "heap.h"
#include "pair.h"
#include <algorithm> // For std::swap

min_heap::min_heap() {}

void min_heap::push(pair<int, int> value) {
    if (count >= INITIAL_CAPACITY) return; // Prevent overflow
    heap[count] = value;
    heapifyUp(count);
    count++;
}

void min_heap::pop() {
    if (count == 0) return;
    std::swap(heap[0], heap[count - 1]);
    count--;
    heapifyDown(0);
}

pair<int, int> min_heap::top() {
    return heap[0];
}

bool min_heap::empty() const {
    return count == 0;
}

int min_heap::size() const {
    return count;
}

void min_heap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        // Compare first element of the pair (min heap)
        if (heap[index].first < heap[parent].first) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void min_heap::heapifyDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        // Compare first element of the pair (min heap)
        if (left < count && heap[left].first < heap[smallest].first) {
            smallest = left;
        }
        if (right < count && heap[right].first < heap[smallest].first) {
            smallest = right;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}