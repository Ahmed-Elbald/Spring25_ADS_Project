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
class Vector {
    T* arr;
    int capacity;
    int size;
public:
    // Constructor
    Vector(int s = 20);

    // Copy constructor
    Vector(const Vector<T>& other);

    // Assignment operator
    Vector<T>& operator=(const Vector<T>& other);

    // Destructor
    ~Vector();

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

/**Documentation
 
 *
 * .
 */

/**
 * Vector(int s = 20)
 *
 * Preconditions:
 * - s must be a positive integer.
 *
 * Postconditions:
 * - A Vector object is created with the specified capacity.
 * -  size is initialized to 20.
 */

/**
 * Vector(const Vector<T>& other)
 *
 * Preconditions:
 * - other must be a valid Vector object.
 *
 * Postconditions:
 * - A new Vector is created as a deep copy of other.
 */

/**
 * Vector<T>& operator=(const Vector<T>& other)
 *
 * Preconditions:
 * - other must be a valid Vector object.
 *
 * Postconditions:
 * - The current Vector becomes a copy of other.
 */

/**
 * ~Vector()
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - Dynamically allocated memory is released.
 */

/**
 * void push_back(T element)
 *
 * Preconditions:
 * - element is of type T.
 *
 * Postconditions:
 * - element is added to the end of the vector.
 * - size is incremented by 1.
 */

/**
 * void push_at(T data, int index)
 *
 * Preconditions:
 * - index must be within the range [0, size].
 *
 * Postconditions:
 * - data is inserted at the specified index.
 * - size is incremented by 1.
 */

/**
 * void pop_back()
 *
 * Preconditions:
 * - Vector must not be empty.
 *
 * Postconditions:
 * - Last element is removed.
 * - size is decremented by 1.
 */

/**
 * int get_size() const
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - Returns the number of elements in the vector.
 */

/**
 * int get_capacity() const
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - Returns the maximum number of elements the vector can hold.
 */

/**
 * T& get_at(int index)
 *
 * Preconditions:
 * - index must be within the range [0, size - 1].
 *
 * Postconditions:
 * - Returns a reference to the element at the specified index.
 */

/**
 * T& operator[](int index)
 *
 * Preconditions:
 * - index must be within the range [0, size - 1].
 *
 * Postconditions:
 * - Returns a reference to the element at the specified index.
 */

#endif  // VECTOR_H
