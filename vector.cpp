//
//  vector.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "vector.h"

/**
 * Constructs a vector with specified initial capacity.
 *
 * Preconditions:
 * - s must be a positive integer.
 *
 * Postconditions:
 * - A Vector object is created with the given capacity.
 * - size is initialized to 0.
 */
template <typename T>
vector<T>::vector(int s) : capacity(s), size(0) {
    arr = new T[s];
}

/**
 *  Copy constructor.
 *
 * Preconditions:
 * - other must be a valid Vector object.
 *
 * Postconditions:
 * - A deep copy of other is created.
 */
template <typename T>
vector<T>::vector(const vector<T>& other) : capacity(other.capacity), size(other.size) {
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

/**
 * Assignment operator.
 *
 * Preconditions:
 * - other must be a valid Vector object.
 *
 * Postconditions:
 * - The current vector becomes a copy of other.
 * - Old memory is deallocated.
 */
template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this == &other) return *this;

    delete[] arr;

    capacity = other.capacity;
    size = other.size;
    arr = new T[capacity];

    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
    return *this;
}

/**
 *  Destructor.
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - Dynamically allocated memory is released.
 */
template <typename T>
vector<T>::~vector() {
    delete[] arr;
    arr = nullptr;
}

template<typename T>
void vector<T>::resize(int newSize, T defaultValue) {
    adjustCapacity(newSize);
    size = newSize;
    for (int i = 0; i < size; i++) {
        arr[i] = defaultValue;
    }
}

/**
 *  Adds an element to the end of the vector.
 *
 * Preconditions:
 * - element must be of type T.
 *
 * Postconditions:
 * - The element is added to the end.
 * - size is incremented.
 * - Capacity is doubled if necessary.
 */
template <typename T>
void vector<T>::push_back(T element) {
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = std::move(arr[i]);
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    arr[size] = std::move(element);
    size++;
}

/**
 *  Inserts an element at the specified index.
 *
 * Preconditions:
 * - index must be in the range [0, size].
 *
 * Postconditions:
 * - The element is inserted at the index.
 * - Elements are shifted.
 * - size is incremented.
 */
template <typename T>
void vector<T>::push_at(T data, int index) {
    if (index < 0 || index > size) return;

    if (size >= capacity) push_back(T());

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = data;
    size++;
}

/**
 * Removes the last element.
 *
 * Preconditions:
 * - Vector must not be empty.
 *
 * Postconditions:
 * - The last element is removed.
 * - size is decremented.
 */
template <typename T>
void vector<T>::pop_back() {
    if (size > 0) size--;
}

/**
 * Accesses element at specified index.
 *
 * Preconditions:
 * - index must be in range [0, size - 1].
 *
 * Postconditions:
 * - Returns a reference to the element.
 * - Throws out_of_range if index is invalid.
 */
template <typename T>
T& vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

/**
 * Returns the number of elements.
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - Returns size.
 */
template <typename T>
int vector<T>::get_size() const {
    return size;
}

/**
 * @brief Returns the capacity of the vector.
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - Returns capacity.
 */
template <typename T>
int vector<T>::get_capacity() const {
    return capacity;
}

/**
 * @brief Returns element at a specific index.
 *
 * Preconditions:
 * - index must be in range [0, size - 1].
 *
 * Postconditions:
 * - Returns a reference to the element.
 * - Throws out_of_range if index is invalid.
 */
template <typename T>
T vector<T>::get_at(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

/**
 * @brief Returns the first element.
 *
 * Preconditions:
 * - Vector must not be empty.
 *
 * Postconditions:
 * - Returns a reference to the first element.
 */
template <typename T>
T& vector<T>::front() {
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}

/**
 * @brief Returns the last element.
 *
 * Preconditions:
 * - Vector must not be empty.
 *
 * Postconditions:
 * - Returns a reference to the last element.
 */
template <typename T>
T& vector<T>::back() {
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[size - 1];
}

template<typename T>
void vector<T>::initialize() {
  for (int i = 0; i < capacity; i++)
    arr[i] = T(); // Default initialization
}

template<typename T>
void vector<T>::allocate() {
  arr = new T[capacity];
}

template<typename T>
void vector<T>::deallocate() {
  if (arr != nullptr)
    delete [] arr;
}

template<typename T>
bool vector<T>::hasSpace(int numOfNewItems) {
  return size + numOfNewItems <= capacity;
}

template<typename T>
bool vector<T>::isEmpty() {
  return size == 0;
}

template<typename T>
void vector<T>::validateSize(int size) {
  if (size < 0)
    throw std::runtime_error("Vector size can not be negative.\n");
}
// Explicit instantiations
template class vector<int>;
template class vector<double>;
template class vector<std::string>;
template class vector<char>;
