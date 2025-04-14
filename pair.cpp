//
//  pair.cpp
//  vector
//
//  Created by youssef salem on 4/2/25.
//

#include "Pair.h"
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
Pair<T1, T2>::Pair() : first(), second() {}

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
Pair<T1, T2>::Pair(const T1& first, const T2& second) : first(first), second(second) {}

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
Pair<T1, T2>::Pair(const Pair<T1, T2>& other) : first(other.first), second(other.second) {}

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
