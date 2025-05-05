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

    // Resizes the vector to the new specified size.
    void resize(int newSizem, T defaultValue = T());

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
    T get_at(int index) const;

    // Return the first element
    T& front();

    // Return the last element
    T& back();

    // []operator overloading
    T& operator[](int index);

    private:
    // Helper methods
    // Initializes the elements of the vector to the default value.
    void initialize();
    // Copies elements from another vector.
    void adjustCapacity(int newCapacity);
    // Allocates memory for the vector.
    void allocate();
    // Deallocates memory.
    void deallocate();
    // Checks if there is enough space for additional elements.
    bool hasSpace(int numOfNewItems = 1);
    // Checks if the vector is empty.
    bool isEmpty();
    // Validates the size parameter.
    void validateSize(int size);
    // Checks if the given range is within the bounds of the vector.
    void checkBoundries(const T* first, const T* last);
};

#endif  // VECTOR_H
