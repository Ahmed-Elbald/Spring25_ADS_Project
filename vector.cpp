//
//  vector.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "Vector.h"

template <typename T>
Vector<T>::Vector(int s) : capacity(s), size(0) {
    arr = new T[s];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) : capacity(other.capacity), size(other.size) {
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

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

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
    arr = nullptr;
}

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

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) size--;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

template <typename T>
int Vector<T>::get_size() const {
    return size;
}

template <typename T>
int Vector<T>::get_capacity() const {
    return capacity;
}

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
