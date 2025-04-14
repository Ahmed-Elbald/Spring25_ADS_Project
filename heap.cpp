#include "heap.h"
using namespace std;

template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::insert(T value) {
    if (count >= INITIAL_CAPACITY) return; // Prevent overflow
    // insert at the end of the heap
    arr[count] = value;
    // heapify up to maintain the heap property
    heapifyUp(count);
    // increment the count
    count++; //
}

template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::pop() {
    if (count == 0) return;
    // swap the root with the last element
    swap(arr[0], arr[count - 1]);
    // remove the last element
    count--;
    // heapify down to maintain the heap property
    heapifyDown(0);
}

// top
template <typename T, typename compare_function, typename get_function>
T Heap<T, compare_function, get_function>::top() {
    return arr[0];
}

// is empty
template <typename T, typename compare_function, typename get_function>
bool Heap<T, compare_function, get_function>::empty() const {
    return count == 0;
}

// size
template <typename T, typename compare_function, typename get_function>
int Heap<T, compare_function, get_function>::size() const {
    return count;
}

// heapify
template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::heapifyUp(int index) {
    //while the index is not the root
    while (index > 0) {
        int parent = (index - 1) / 2;
        // if the current element is less than its parent
        if (compare(get(arr[index]), get(arr[parent]))) {
            swap(arr[index], arr[parent]);
            index = parent; // update the index to the parent
        } else {
            break;
        }
    }
}


template <typename T, typename compare_function, typename get_function>
void Heap<T, compare_function, get_function>::heapifyDown(int index) {
    while (true) {
        // calculate the left and right children
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index; // assume the current index is the best

        // if the left child is the best
        if (left < count && compare(get(arr[left]), get(arr[best]))) {
            best = left;
        }
        // if the right child is the best
        if (right < count && compare(get(arr[right]), get(arr[best]))) {
            best = right;
        }
        // if the best is not the current index , swap the current index with the best
        if (best != index) {
            swap(arr[index], arr[best]);
            index = best;
        } else { // if the best is the current index, then we are done , break 
            break;
        }
    }
}

// Template instantiation
template class Heap<int, function<bool(int, int)>, function<int(int)>>;
template class Heap<pair<int, int>, function<bool(int, int)>, function<int(pair<int, int>)>>;
template class Heap<tuple<int, int, int>, function<bool(int, int)>, function<int(tuple<int, int, int>)>>;

