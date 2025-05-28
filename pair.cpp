#include "pair.h"
#include <string>

// Default constructor definition removed to avoid redefinition error.

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

/**
 * Copy constructor.
 *
 * Preconditions:
 * - other must be a valid Pair object.
 *
 * Postconditions:
 * - A new Pair object is created as a copy of other.
 */

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
PAIR_H::pair<T1, T2>& PAIR_H::pair<T1, T2>::operator=(const PAIR_H::pair<T1, T2>& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

template class PAIR_H::pair<long long, long long>;
template class PAIR_H::pair<int, int>;