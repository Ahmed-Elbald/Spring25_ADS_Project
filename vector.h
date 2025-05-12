#ifndef VECTOR_H
#define VECTOR_H

// Including required libaries
#include <iostream>
#include <assert.h>

namespace custom {
  // Vector template class
  template<typename T>
  class vector {
    private:
      T* container_ = nullptr; // Pointer to dynamically allocated array.
      int size_;                // Current number of elements in the vector.
      int capacity_;            // Maximum number of elements the vector can hold.
      T defaultValue_;          // Default value for elements.

    public:
      // Constructors
      // Parameterized
      vector(int = 0, T = T());
      // Copy
      vector(const vector<T>& vectorToCopy);

      // Destructor
      ~vector();

      // Methods
      // Resizes the vector to the new specified size.
      void resize(int newSize, T filler = T());
      // Adds a new element to the end of the vector.
      void push_back(T item);
      // Removes the last element from the vector.
      void pop_back();
      // Inserts a single element at the specified position.
      void insert(T* beginIterator, T item);
      // Inserts multiple elements at the specified position.
      void insert(T* beginIterator, int numOfNewItems, T item);
      // Inserts a range of elements at the specified position.
      void insert(T* beginIterator, T* endIterator, T item);
      // Erases a single element at the specified position.
      void erase(T* beginIterator);
      // Erases multiple elements starting from the specified position.
      void erase(T* beginIterator, int numOfDeletedItems);
      // Erases a range of elements.
      void erase(T* beginIterator, T* endIterator);
      // pointer to the first element of the vector.
      T& front() const;
      // pointer to the last element of the vector.
      T& back() const;

      // Overloaded Operators
      // Assignment operator.
      vector<T>& operator =(const vector<T>& vectorToCopy);
      // Equality operator.
      bool operator ==(const vector<T>& vectorToCompare);
      // Inequality operator.
      bool operator !=(const vector<T>& vectorToCompare);
      // Addition assignment operator.
      vector<T>& operator +=(const vector<T>& vectorToAdd);
      // Subtraction assignment operator.
      vector<T>& operator -=(const vector<T>& vectorToSubtract);
      // Subscript operator
      T& operator [](int index);
      const T& operator [](int index) const;
      // Post-increment operator.
      vector<T> operator ++(int);
      // Pre-increment operator.
      vector<T>& operator ++();
      // Post-decrement operator.
      vector<T> operator --(int);
      // Pre-decrement operator.
      vector<T>& operator --();

      // Getters
      // Returns the current size of the vector.
      int size() const;
      // Returns the current capacity of the vector.
      int capacity() const;
      // Returns a pointer to the beginning of the vector.
      T* begin() const;
      // Returns a pointer to the end of the vector.
      T* end() const;

    private:
      // Helper methods
      // Initializes the elements of the vector to the default value.
      void initialize();
      // Copies elements from another vector.
      void copy(const vector<T>& vectorToCopy);
      // Adjusts the capacity of the vector.
      void adjustCapacity(int newCapacity);
      // Allocates memory for the vector.
      void allocate();
      // Deallocates memory.
      void deallocate();
      // Checks if there is enough space for additional elements.
      bool hasSpace(int numOfNewItems = 1);
      // Checks if the vector is empty.
      bool isEmpty() const;
      // Validates the size parameter.
      void validateSize(int size);
      // Checks if the given range is within the bounds of the vector.
      void checkBoundries(const T* first, const T* last);
  };
}

#endif // VECTOR_H