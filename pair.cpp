//
//  pair.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "pair.h"
#include <string>

/**
 * Default constructor.
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - A Pair object is created with default-initialized values.
 */
template <typename T1, typename T2>
pair<T1, T2>::pair() : first(), second() {}

/**
 * Parameterized constructor.
 *
 * Preconditions:
 * - first must be a valid object of type T1.
 * - second must be a valid object of type T2.
 *
 * Postconditions:
 * - A Pair object is created with the given first and second values.
 */
template <typename T1, typename T2>
pair<T1, T2>::pair(const T1& first, const T2& second) : first(first), second(second) {}

/**
 * Copy constructor.
 *
 * Preconditions:
 * - other must be a valid Pair object.
 *
 * Postconditions:
 * - A new Pair object is created as a copy of other.
 */
template <typename T1, typename T2>
pair<T1, T2>::pair(const pair<T1, T2>& other) : first(other.first), second(other.second) {}

/**
 * Assignment operator.
 *
 * Preconditions:
 * - other must be a valid Pair object.
 *
 * Postconditions:
 * - The current Pair object is assigned the values of other.
 * - Returns a reference to the current object.
 */
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
