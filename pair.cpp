//
//  pair.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "pair.h"
#include <string>

// Default constructor
template <typename T1, typename T2>
pair<T1, T2>::pair() : first(), second() {}

// Parameterized constructor
template <typename T1, typename T2>
pair<T1, T2>::pair(const T1& first, const T2& second) : first(first), second(second) {}

// Copy constructor
template <typename T1, typename T2>
pair<T1, T2>::pair(const pair<T1, T2>& other) : first(other.first), second(other.second) {}

// Assignment operator
template <typename T1, typename T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}


template class pair<int, int>;
template class pair<int, double>;
template class pair<pair<int, int>, int>;
template class pair<std::string, std::string>;

template class pair<double, double>;
template class pair<int, std::string>;

