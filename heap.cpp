#include "heap.h"
using namespace std;

template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::insert(T value) {
    if (count >= INITIAL_CAPACITY) return; // Prevent overflow
    arr[count] = value;
    heapifyUp(count);
    count++;
}

template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::pop() {
    if (count == 0) return;
    swap(arr[0], arr[count - 1]);
    count--;
    heapifyDown(0);
}

template <typename T, typename compare_function, typename get_function>
T Heap<T, compare_function, get_function>::top() {
    return arr[0];
}

template <typename T, typename compare_function, typename get_function>
bool Heap<T, compare_function, get_function>::empty() const {
    return count == 0;
}

template <typename T, typename compare_function, typename get_function>
int Heap<T, compare_function, get_function>::size() const {
    return count;
}

template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (compare(get(arr[index]), get(arr[parent]))) {
            swap(arr[index], arr[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::heapifyDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < count && compare(get(arr[left]), get(arr[best]))) {
            best = left;
        }
        if (right < count && compare(get(arr[right]), get(arr[best]))) {
            best = right;
        }
        if (best != index) {
            swap(arr[index], arr[best]);
            index = best;
        } else {
            break;
        }
    }
}

// Template instantiation
template class Heap<int, function<bool(int, int)>, function<int(int)>>;
template class Heap<pair<int, int>, function<bool(int, int)>, function<int(pair<int, int>)>>;
template class Heap<tuple<int, int, int>, function<bool(int, int)>, function<int(tuple<int, int, int>)>>;

