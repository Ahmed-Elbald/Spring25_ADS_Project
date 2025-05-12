#include "vector.h"
#include <stdexcept>

template<typename T>
custom::vector<T>::vector(int initialSize, T defaultValue) {

  validateSize(initialSize);
  size_ = capacity_ = initialSize;
  defaultValue_ = defaultValue;
  allocate();
  initialize();
}

template<typename T>
custom::vector<T>::vector(const custom::vector<T>& vectorToCopy) {
  copy(vectorToCopy);
}

template<typename T>
custom::vector<T>::~vector() {
  delete [] container_;
}

template<typename T>
custom::vector<T>& custom::vector<T>::operator =(const custom::vector<T>& vectorToCopy) {
  if (this != &vectorToCopy)
    copy(vectorToCopy);

  return *this;
}

template<typename T>
bool custom::vector<T>::operator ==(const custom::vector<T>& vectorToCompare) {
  if (size_ != vectorToCompare.size_) return false;
  for(int i = 0; i < size_; i++)
    if (container_[i] != vectorToCompare.container_[i])
      return false;

  return true;
}

template<typename T>
bool custom::vector<T>::operator !=(const custom::vector<T>& vectorToCompare) {
  return !operator==(vectorToCompare);
}

template<typename T>
custom::vector<T>& custom::vector<T>::operator +=(const custom::vector<T>& vectorToAdd) {
  if (size_ != vectorToAdd.size_)
    throw std::runtime_error("Can not add vectors of different sizes\n");

  for(int i = 0; i < size_; i++)
    container_[i] += vectorToAdd.container_[i];

  return *this;

}


template<typename T>
custom::vector<T> operator +(custom::vector<T>& lhVector, custom::vector<T>& rhVector) {
  custom::vector<T> newVector(lhVector);
  newVector += rhVector;
  return newVector;
}

template<typename T>
custom::vector<T>& custom::vector<T>::operator -=(const custom::vector<T>& vectorToSubtract) {
  if (size_ != vectorToSubtract.size_)
    throw std::runtime_error("Can not subtract vectors of different sizes\n");

  for(int i = 0; i < size_; i++)
    container_[i] -= vectorToSubtract.container_[i];

  return *this;

}

template<typename T>
custom::vector<T> operator -(custom::vector<T>& lhVector, custom::vector<T>& rhVector) {
  custom::vector<T> newVector(lhVector);
  newVector -= rhVector;
  return newVector;
}

template<typename T>
T& custom::vector<T>::operator [](int index) {
  if (index < 0 || index >= size_)
    throw std::out_of_range("Out of range index.\n");
  return container_[index];
}

template<typename T>
const T& custom::vector<T>::operator [](int index) const {
  if (index < 0 || index >= size_)
    throw std::out_of_range("Out of range index.\n");
  return container_[index];
}

template<typename T>
custom::vector<T> custom::vector<T>::operator ++(int) {

  custom::vector<T> tmp(*this);
  this->operator++();
  return tmp;
}

template<typename T>
custom::vector<T>& custom::vector<T>::operator ++() {

  for(int i = 0; i < size_; i++)
    container_[i]++;

  return *this;
}

template<typename T>
custom::vector<T> custom::vector<T>::operator --(int) {

  custom::vector<T> tmp(*this);
  this->operator--();
  return tmp;
}

template<typename T>
custom::vector<T>& custom::vector<T>::operator --() {

  for(int i = 0; i < size_; i++)
    container_[i]--;

  return *this;
}

template<typename T>
void custom::vector<T>::resize(int newSize, T filler) {
  adjustCapacity(newSize);
  size_ = newSize;

  // Fill the new elements with the default value
  for (int i = 0; i < size_; i++)
    container_[i] = filler;
}

template<typename T>
void custom::vector<T>::push_back(T item) {

  if (!hasSpace())
    adjustCapacity(capacity_ * 2);

  container_[size_++] = item;
}

template<typename T>
void custom::vector<T>::pop_back() {
  if (isEmpty()) 
    throw std::runtime_error("The vector is already empty.\n");

  size_--;
}

template<typename T>
void custom::vector<T>::insert(T* beginIterator, T item) {
  insert(beginIterator, 1, item);
}

template<typename T>
void custom::vector<T>::insert(T* beginIterator, int numOfNewItems, T item) {
  insert(beginIterator, beginIterator + numOfNewItems, item);
}

template<typename T>
void custom::vector<T>::insert(T* beginIterator, T* endIterator, T item) {

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
void custom::vector<T>::erase(T* beginIterator) {
  erase(beginIterator, 1);
}

template<typename T>
void custom::vector<T>::erase(T* beginIterator, int numOfDeletedItems) {
  erase(beginIterator, beginIterator + numOfDeletedItems);
}

template<typename T>
void custom::vector<T>::erase(T* beginIterator, T* endIterator) {

  checkBoundries(beginIterator, endIterator);

  int numOfDeletedItems = endIterator - beginIterator;

  for(T* start = beginIterator; start < end(); start++)
    *start = *(start + numOfDeletedItems);

  size_ -= numOfDeletedItems;

}

template<typename T>
T& custom::vector<T>::front() const {
  if (isEmpty())
    throw std::runtime_error("The vector is empty.\n");
  return container_[0];
}

template<typename T>
T& custom::vector<T>::back() const {
  if (isEmpty())
    throw std::runtime_error("The vector is empty.\n");
  return container_[size_ - 1];
}

template<typename T>
int custom::vector<T>::size() const {return size_;}

template<typename T>
int custom::vector<T>::capacity() const {return capacity_;}

template<typename T>
T* custom::vector<T>::begin() const {return container_;}

template<typename T>
T* custom::vector<T>::end() const {return container_ + capacity_;}

template<typename T>
void custom::vector<T>::copy(const custom::vector<T>& vectorToCopy) {
  capacity_ = vectorToCopy.capacity_;
  size_ = vectorToCopy.size_;
  defaultValue_ = vectorToCopy.defaultValue_;

  deallocate();
  allocate();

  for (int i = 0; i < size_; i++)
    container_[i] = vectorToCopy.container_[i];
}

template<typename T>
void custom::vector<T>::adjustCapacity(int newCapacity) {
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
void custom::vector<T>::initialize() {
  for (int i = 0; i < capacity_; i++)
    container_[i] = defaultValue_;
}

template<typename T>
void custom::vector<T>::allocate() {
  container_ = new T[capacity_];
  assert(container_ != nullptr);
}

template<typename T>
void custom::vector<T>::deallocate() {
  if (container_ != nullptr)
    delete [] container_;
}

template<typename T>
bool custom::vector<T>::hasSpace(int numOfNewItems) {
  return size_ + numOfNewItems <= capacity_;
}

template<typename T>
bool custom::vector<T>::isEmpty() const {
  return (size_ == 0);
}

template<typename T>
void custom::vector<T>::validateSize(int size) {
  if (size < 0)
    throw std::runtime_error("Vector size can not be negative.\n");
}

template<typename T>
void custom::vector<T>::checkBoundries(const T* first, const T* last) {
  if (first > last)
    throw std::runtime_error("Start position can not be greater than end position.\n");
  
  if (first < begin() || last > end())
    throw std::runtime_error("Position is out of boundries.\n");
}