// Including required libaries
#include <iostream>
#include <assert.h>

// Using std as the default name space
using namespace std;

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
    void resize(int newSize);
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

    // Overloaded Operators
    // Assignment operator.
    vector<T>& operator =(const vector<T>& vectorToCopy);
    // Assignment operator for passed rvalues.
    vector<T>& operator =(vector<T>&& vectorToCopy);
    // Equality operator.
    bool operator ==(const vector<T>& vectorToCompare);
    // Inequality operator.
    bool operator !=(const vector<T>& vectorToCompare);
    // Equality operator for comparing a vector with an rvalue.
    bool operator ==(vector<T>&& vectorToCompare);
    // Inequality operator for comparing a vector with an rvalue.
    bool operator !=(vector<T>&& vectorToCompare);
    // Addition assignment operator.
    vector<T>& operator +=(const vector<T>& vectorToAdd);
    // Subtraction assignment operator.
    vector<T>& operator -=(const vector<T>& vectorToSubtract);
    // Addition assignment operator for rvalue.
    vector<T>& operator +=(vector<T>&& vectorToAdd);
    // Subtraction assignment operator for rvalue.
    vector<T>& operator -=(vector<T>&& vectorToSubtract);
    // Subscript operator
    T& operator [](int index);
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
    bool isEmpty();
    // Validates the size parameter.
    void validateSize(int size);
    // Checks if the given range is within the bounds of the vector.
    void checkBoundries(const T* first, const T* last);

    // Friends for stream I/O
  public:
    // Friend functions for stream output.
    template<typename S>
    friend ostream& operator <<(ostream&, const vector<S>&);
    // Friend function for stream output with rvalue.
    template<typename S>
    friend ostream& operator <<(ostream&, vector<S>&&);
    // Friend functions for stream input.
    template<typename S>
    friend istream& operator >>(istream&, const vector<S>&);
};


template<typename T>
vector<T>::vector(int initialSize, T defaultValue) {

  validateSize(initialSize);
  size_ = capacity_ = initialSize;
  defaultValue_ = defaultValue;
  allocate();
  initialize();
}

template<typename T>
vector<T>::vector(const vector<T>& vectorToCopy) {
  copy(vectorToCopy);
}

template<typename T>
vector<T>::~vector() {
  delete [] container_;
}

template<typename T>
vector<T>& vector<T>::operator =(const vector<T>& vectorToCopy) {
  if (this != &vectorToCopy)
    copy(vectorToCopy);

  return *this;
}
template<typename T>
vector<T>& vector<T>::operator =(vector<T>&& vectorToCopy) {
  copy(vectorToCopy);
  return *this;
}

template<typename T>
bool vector<T>::operator ==(const vector<T>& vectorToCompare) {
  if (size_ != vectorToCompare.size_) return false;
  for(int i = 0; i < size_; i++)
    if (container_[i] != vectorToCompare.container_[i])
      return false;

  return true;
}

template<typename T>
bool vector<T>::operator ==(vector<T>&& vectorToCompare) {
  return operator==(static_cast<vector<T>&>(vectorToCompare));
}

template<typename T>
bool vector<T>::operator !=(const vector<T>& vectorToCompare) {
  return !operator==(vectorToCompare);
}

template<typename T>
bool vector<T>::operator !=(vector<T>&& vectorToCompare) {
  return !operator==(static_cast<vector<T>&>(vectorToCompare));
}

template<typename T>
vector<T>& vector<T>::operator +=(vector<T>&& vectorToAdd) {
  return operator+=(static_cast<vector<T>&>(vectorToAdd));
}

template<typename T>
vector<T>& vector<T>::operator +=(const vector<T>& vectorToAdd) {
  if (size_ != vectorToAdd.size_)
    throw runtime_error("Can not add vectors of different sizes\n");

  for(int i = 0; i < size_; i++)
    container_[i] += vectorToAdd.container_[i];

  return *this;

}

template<typename T>
vector<T> operator +(vector<T>&& lhVector, vector<T>&& rhVector) {
  return operator +(
    static_cast<vector<T>&>(lhVector),
    static_cast<vector<T>&>(rhVector)
  );
}

template<typename T>
vector<T> operator +(vector<T>& lhVector, vector<T>&& rhVector) {
  return operator +(
    lhVector,
    static_cast<vector<T>&>(rhVector)
  );
}

template<typename T>
vector<T> operator +(vector<T>&& lhVector, vector<T>& rhVector) {
  return operator +(
    static_cast<vector<T>&>(lhVector),
    rhVector
  );
}

template<typename T>
vector<T> operator +(vector<T>& lhVector, vector<T>& rhVector) {
  vector<T> newVector(lhVector);
  newVector += rhVector;
  return newVector;
}


template<typename T>
vector<T>& vector<T>::operator -=(vector<T>&& vectorToSubtract) {
  return operator-=(static_cast<vector<T>&>(vectorToSubtract));
}

template<typename T>
vector<T>& vector<T>::operator -=(const vector<T>& vectorToSubtract) {
  if (size_ != vectorToSubtract.size_)
    throw runtime_error("Can not subtract vectors of different sizes\n");

  for(int i = 0; i < size_; i++)
    container_[i] -= vectorToSubtract.container_[i];

  return *this;

}

template<typename T>
vector<T> operator -(vector<T>&& lhVector, vector<T>&& rhVector) {
  return operator -(
    static_cast<vector<T>&>(lhVector),
    static_cast<vector<T>&>(rhVector)
  );
}

template<typename T>
vector<T> operator -(vector<T>& lhVector, vector<T>&& rhVector) {
  return operator -(
    lhVector,
    static_cast<vector<T>&>(rhVector)
  );
}

template<typename T>
vector<T> operator -(vector<T>&& lhVector, vector<T>& rhVector) {
  return operator -(
    static_cast<vector<T>&>(lhVector),
    rhVector
  );
}

template<typename T>
vector<T> operator -(vector<T>& lhVector, vector<T>& rhVector) {
  vector<T> newVector(lhVector);
  newVector -= rhVector;
  return newVector;
}

template<typename T>
T& vector<T>::operator [](int index) {
  if (index < 0 || index >= size_)
    throw out_of_range("Out of range index.\n");
  return container_[index];
}

template<typename T>
vector<T> vector<T>::operator ++(int) {

  vector<T> tmp(*this);
  this->operator++();
  return tmp;
}

template<typename T>
vector<T>& vector<T>::operator ++() {

  for(int i = 0; i < size_; i++)
    container_[i]++;

  return *this;
}

template<typename T>
vector<T> vector<T>::operator --(int) {

  vector<T> tmp(*this);
  this->operator--();
  return tmp;
}

template<typename T>
vector<T>& vector<T>::operator --() {

  for(int i = 0; i < size_; i++)
    container_[i]--;

  return *this;
}

template<typename T>
void vector<T>::resize(int newSize) {
  adjustCapacity(newSize);
  size_ = newSize;
}

template<typename T>
void vector<T>::push_back(T item) {

  if (!hasSpace())
    adjustCapacity(capacity_ * 2);

  container_[size_++] = item;
}

template<typename T>
void vector<T>::pop_back() {
  if (isEmpty()) 
    throw runtime_error("The vector is already empty.\n");

  size_--;
}

template<typename T>
void vector<T>::insert(T* beginIterator, T item) {
  insert(beginIterator, 1, item);
}

template<typename T>
void vector<T>::insert(T* beginIterator, int numOfNewItems, T item) {
  insert(beginIterator, beginIterator + numOfNewItems, item);
}

template<typename T>
void vector<T>::insert(T* beginIterator, T* endIterator, T item) {

  checkBoundries(beginIterator, endIterator);

  int startIndex = beginIterator - begin(), numOfNewItems = endIterator - beginIterator;
  if (!hasSpace(numOfNewItems))
    adjustCapacity((capacity_ + numOfNewItems) * 2);

  beginIterator = container_ + startIndex;
  endIterator = beginIterator + numOfNewItems;

  for(T* end = container_ + size_ - 1; end >= beginIterator; end--)
    *(end + numOfNewItems) = *end;

  for(T* begin = beginIterator; begin != endIterator; begin++)
    *begin = item;

  size_ += numOfNewItems;

}

template<typename T>
void vector<T>::erase(T* beginIterator) {
  erase(beginIterator, 1);
}

template<typename T>
void vector<T>::erase(T* beginIterator, int numOfDeletedItems) {
  erase(beginIterator, beginIterator + numOfDeletedItems);
}

template<typename T>
void vector<T>::erase(T* beginIterator, T* endIterator) {

  checkBoundries(beginIterator, endIterator);

  int numOfDeletedItems = endIterator - beginIterator;

  for(T* start = beginIterator; start < end(); start++)
    *start = *(start + numOfDeletedItems);

  size_ -= numOfDeletedItems;

}

template<typename T>
int vector<T>::size() const {return size_;}

template<typename T>
int vector<T>::capacity() const {return capacity_;}

template<typename T>
T* vector<T>::begin() const {return container_;}

template<typename T>
T* vector<T>::end() const {return container_ + capacity_;}

template<typename T>
void vector<T>::copy(const vector<T>& vectorToCopy) {
  capacity_ = vectorToCopy.capacity_;
  size_ = vectorToCopy.size_;
  defaultValue_ = vectorToCopy.defaultValue_;

  deallocate();
  allocate();

  for (int i = 0; i < size_; i++)
    container_[i] = vectorToCopy.container_[i];
}

template<typename T>
void vector<T>::adjustCapacity(int newCapacity) {
  validateSize(newCapacity);
  if (newCapacity == 0) newCapacity = 10;
  capacity_ = newCapacity;

  T* tmp = container_;
  allocate();
  for(int i = 0; i < size_; i++)
    container_[i] = tmp[i];

  delete [] tmp;
}

template<typename T>
void vector<T>::initialize() {
  for (int i = 0; i < capacity_; i++)
    container_[i] = defaultValue_;
}

template<typename T>
void vector<T>::allocate() {
  container_ = new T[capacity_];
  assert(container_ != nullptr);
}

template<typename T>
void vector<T>::deallocate() {
  if (container_ != nullptr)
    delete [] container_;
}

template<typename T>
bool vector<T>::hasSpace(int numOfNewItems) {
  return size_ + numOfNewItems <= capacity_;
}

template<typename T>
bool vector<T>::isEmpty() {
  return size_ == 0;
}

template<typename T>
void vector<T>::validateSize(int size) {
  if (size < 0)
    throw runtime_error("Vector size can not be negative.\n");
}

template<typename T>
void vector<T>::checkBoundries(const T* first, const T* last) {
  if (first > last)
    throw runtime_error("Start position can not be greater than end position.\n");
  
  if (first < begin() || last > end())
    throw runtime_error("Position is out of boundries.\n");
}

template<typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
  for(int i = 0; i < v.size_; i++)
    out << v.container_[i] << ' ';
  return out;
};
template<typename T>
ostream& operator <<(ostream& out, vector<T>&& v) {
  return operator <<(out, static_cast<vector<T>&>(v));
};
template<typename T>
istream& operator >>(istream& in, const vector<T>& v) {
  for(int i = 0; i < v.size_; i++)
    in >> v.container_[i];
  return in;
};

int main() {
  vector<int> x(4, 5);
  x += x;
  cout << x;
}
