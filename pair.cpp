//
//  pair.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "Pair.h"
#include <string>

// Default constructor
template <typename T1, typename T2>
Pair<T1, T2>::Pair() : first(), second() {}

// Parameterized constructor
template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first, const T2& second) : first(first), second(second) {}

// Copy constructor
template <typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair<T1, T2>& other) : first(other.first), second(other.second) {}

// Assignment operator
template <typename T1, typename T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair<T1, T2>& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}


template class Pair<int, int>;
template class Pair<int, double>;
template class Pair<std::string, std::string>;

template class Pair<double, double>;
template class Pair<int, std::string>;

