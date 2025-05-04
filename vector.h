//
//  Vector.h
//  vector
//
//  Created by youssef salem on 3/25/25.
//
#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <utility>
#include <string>
template <typename T>
class vector {
    T* arr;
    int capacity;
    int size;
public:
    // Constructor
    vector(int s = 20);

    // Copy constructor
    vector(const vector<T>& other);

    // Assignment operator
    vector<T>& operator=(const vector<T>& other);

    // Destructor
    ~vector();

    // push_back method
    void push_back(T element);

    // Adding an element at a specific index
    void push_at(T data, int index);

    // pop back method
    void pop_back();

    // getting the current size of the vector
    int get_size() const;

    // returning the current capacity of the vector
    int get_capacity() const;

    // Returning the element at the specified index
    T& get_at(int index);

    // []operator overloading
    T& operator[](int index);
};

#endif  // VECTOR_H
