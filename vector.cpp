//
//  vector.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "Vector.h"

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
Vector<T>::Vector(int s) : capacity(s), size(0) {
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
Vector<T>::Vector(const Vector<T>& other) : capacity(other.capacity), size(other.size) {
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
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
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
Vector<T>::~Vector() {
    delete[] arr;
    arr = nullptr;
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
void Vector<T>::push_back(T element) {
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
void Vector<T>::push_at(T data, int index) {
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
void Vector<T>::pop_back() {
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
T& Vector<T>::operator[](int index) {
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
int Vector<T>::get_size() const {
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
int Vector<T>::get_capacity() const {
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
T& Vector<T>::get_at(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

// Explicit instantiations
template class Vector<int>;
template class Vector<double>;
template class Vector<std::string>;
template class Vector<char>;
